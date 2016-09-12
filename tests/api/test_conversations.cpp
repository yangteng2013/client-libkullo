/* Copyright 2013–2016 Kullo GmbH. All rights reserved. */
#include "tests/api/apimodeltest.h"

#include <kulloclient/api/Address.h>
#include <kulloclient/api/Conversations.h>
#include <kulloclient/api/DateTime.h>
#include <kulloclient/api_impl/conversationsimpl.h>
#include <kulloclient/dao/conversationdao.h>
#include <kulloclient/event/conversationaddedevent.h>
#include <kulloclient/event/conversationwillberemovedevent.h>

using namespace testing;
using namespace Kullo;

K_TEST(ApiConversationsStatic, emptyConversationTimestampIsInTheFuture)
{
    EXPECT_THAT(Api::DateTime::nowUtc(),
                Lt(Api::Conversations::emptyConversationTimestamp()));
}

class ApiConversations : public ApiModelTest
{
public:
    ApiConversations()
    {
        // emptyData_.id is autogenerated by and read from DB
        emptyData_.participant1 = "empty1#example.com";
        emptyData_.participant2 = "empty2#example.com";
        auto emptyParticipants =
                emptyData_.participant1 + "," + emptyData_.participant2;

        // data_.id is autogenerated by and read from DB
        data_.participant1 = "1#example.com";
        data_.participant2 = "2#example.com";
        auto participants = data_.participant1 + "," + data_.participant2;

        messageData_.id = 0;
        messageData_.dateSent = Api::DateTime(2015, 6, 23, 16, 06, 00, 120);
        messageData_.dateReceived = Api::DateTime(2015, 6, 23, 16, 06, 01, 120);

        dbSession_ = Db::makeSession(dbPath_);
        Db::migrate(dbSession_);

        Dao::ConversationDao emptyDao(dbSession_);
        emptyDao.setParticipants(emptyParticipants);
        emptyDao.save();
        emptyData_.id = emptyDao.id();

        Dao::ConversationDao dao(dbSession_);
        dao.setParticipants(participants);
        dao.save();
        data_.id = dao.id();

        Dao::MessageDao messageDao(dbSession_);
        messageDao.setConversationId(data_.id);
        messageDao.setId(messageData_.id);
        messageDao.setDateSent(messageData_.dateSent->toString());
        messageDao.setDateReceived(messageData_.dateReceived->toString());
        messageDao.save(Dao::CreateOld::No);

        makeSession();
        uut_ = session_->conversations();
    }

protected:
    struct
    {
        int64_t id;
        std::string participant1;
        std::string participant2;
    } emptyData_;

    struct
    {
        int64_t id;
        std::string participant1;
        std::string participant2;
    } data_;

    struct
    {
        int64_t id;
        boost::optional<Api::DateTime> dateSent;
        boost::optional<Api::DateTime> dateReceived;
    } messageData_;

    Db::SharedSessionPtr dbSession_;
    std::shared_ptr<Api::Conversations> uut_;
};

K_TEST_F(ApiConversations, allWorks)
{
    auto conversations = uut_->all();
    EXPECT_THAT(conversations, WhenSorted(ElementsAre(1, 2)));
}

K_TEST_F(ApiConversations, getWorks)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant2));
    EXPECT_THAT(uut_->get(participants), Eq(data_.id));

    participants.emplace(Api::Address::create("nosuchuser#example.com"));
    EXPECT_THAT(uut_->get(participants), Eq(-1));
}

K_TEST_F(ApiConversations, getWorksWithDuplicateAddresses)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant2));
    EXPECT_THAT(uut_->get(participants), Eq(data_.id));

    participants.emplace(Api::Address::create("nosuchuser#example.com"));
    EXPECT_THAT(uut_->get(participants), Eq(-1));
}

K_TEST_F(ApiConversations, addReturnsExistingConversation)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant2));

    EXPECT_THAT(uut_->add(participants), Eq(data_.id));
}

K_TEST_F(ApiConversations, addWorksWithDuplicateAddresses)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant2));
    auto convId = uut_->add(participants);

    // must not create new conversation but return existing with {part1, part2}
    EXPECT_THAT(convId, Eq(data_.id));
}

K_TEST_F(ApiConversations, addReturnsNewConversation)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create(data_.participant1));
    participants.emplace(Api::Address::create(data_.participant2));
    participants.emplace(Api::Address::create("nosuchuser#example.com"));
    auto convId = uut_->add(participants);

    EXPECT_THAT(convId, Ge(0));
    EXPECT_THAT(convId, Ne(data_.id));
}

K_TEST_F(ApiConversations, addStoresToMemoryAndDatabase)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create("local-new-guy1#example.com"));
    participants.emplace(Api::Address::create("local-new-guy2#example.com"));

    auto convId = uut_->add(participants);

    // non-existing conversation defaults to empty participants set
    EXPECT_THAT(uut_->participants(convId).size(), Eq(2u));

    // Existing in database
    {
        auto dao = Dao::ConversationDao::load(convId, dbSession_);
        ASSERT_THAT(dao, Not(IsNull()));
        EXPECT_THAT(dao->participantsList().size(), Eq(2u));
    }
}

K_TEST_F(ApiConversations, addEmitsEvent)
{
    std::unordered_set<std::shared_ptr<Api::Address>> participants;
    participants.emplace(Api::Address::create("local-new-guy1#example.com"));
    participants.emplace(Api::Address::create("local-new-guy2#example.com"));

    auto addedConvId = uut_->add(participants);

    auto type = std::type_index(typeid(Event::ConversationAddedEvent));
    EXPECT_THAT(sessionListener_->internalEventCount(type), Eq(1));

    // send conversationAdded event
    auto uutImpl = std::dynamic_pointer_cast<ApiImpl::ConversationsImpl>(uut_);
    ASSERT_THAT(uutImpl, Not(IsNull()));
    auto events = uutImpl->conversationAdded(addedConvId);

    // we'd like to get a notification that the conversation has been removed
    EXPECT_THAT(events, Contains(
                    Api::Event(Api::EventType::ConversationAdded, addedConvId, -1, -1))
                );

    // make sure that conversationAdded() updated the UUT
    EXPECT_THAT(uut_->participants(addedConvId).size(), Eq(2u));
}

K_TEST_F(ApiConversations, addDoesntAcceptCurrentUser)
{
    const auto currentUserAddressString = address_->toString();

    std::unordered_set<std::shared_ptr<Api::Address>> participants1;
    participants1.emplace(Api::Address::create(currentUserAddressString));

    std::unordered_set<std::shared_ptr<Api::Address>> participants2;
    participants2.emplace(Api::Address::create("local-new-guy1#example.com"));
    participants2.emplace(Api::Address::create(currentUserAddressString));

    std::unordered_set<std::shared_ptr<Api::Address>> participants3;
    participants3.emplace(Api::Address::create("local-new-guy1#example.com"));
    participants3.emplace(Api::Address::create(currentUserAddressString));
    participants3.emplace(Api::Address::create("local-new-guy2#example.com"));

    EXPECT_THROW(uut_->add(participants1), Util::AssertionFailed);
    EXPECT_THROW(uut_->add(participants2), Util::AssertionFailed);
    EXPECT_THROW(uut_->add(participants3), Util::AssertionFailed);
}

K_TEST_F(ApiConversations, triggerRemovalWorks)
{
    // Existing in memory
    ASSERT_THAT(uut_->participants(data_.id).size(), Gt(0u));

    // Existing in database
    auto dao1 = Dao::ConversationDao::load(data_.id, dbSession_);
    EXPECT_THAT(dao1, Not(IsNull()));

    uut_->triggerRemoval(data_.id);

    // Deleted in memory
    EXPECT_THAT(uut_->participants(data_.id).size(), Eq(0u));

    // Deleted in database
    auto dao2 = Dao::ConversationDao::load(data_.id, dbSession_);
    EXPECT_THAT(dao2, IsNull());
}

K_TEST_F(ApiConversations, triggerRemovalEmitsEvents)
{
    auto type = std::type_index(typeid(Event::ConversationWillBeRemovedEvent));
    EXPECT_THAT(sessionListener_->internalEventCount(type), Eq(0));

    uut_->triggerRemoval(data_.id);

    // a ConversationRemoved API event must be emitted
    auto events = sessionListener_->externalEvents();
    EXPECT_THAT(events, Contains(
                    Api::Event(Api::EventType::ConversationRemoved, data_.id, -1, -1))
                );

    EXPECT_THAT(sessionListener_->internalEventCount(type), Eq(1));
}

K_TEST_F(ApiConversations, participantsWorks)
{
    auto participants = uut_->participants(data_.id);
    ASSERT_THAT(participants.size(), Eq(2u));
    bool found1 = false, found2 = false;
    for (auto &part : participants)
    {
        found1 = found1 || (part->toString() == data_.participant1);
        found2 = found2 || (part->toString() == data_.participant2);
    }
    EXPECT_THAT(found1, Eq(true));
    EXPECT_THAT(found2, Eq(true));

    EXPECT_THAT(uut_->participants(42), IsEmpty());
}

K_TEST_F(ApiConversations, totalMessagesWorks)
{
    EXPECT_THAT(uut_->totalMessages(emptyData_.id), Eq(0));
    EXPECT_THAT(uut_->totalMessages(data_.id), Eq(1));

    EXPECT_THAT(uut_->totalMessages(42), Eq(0));
}

K_TEST_F(ApiConversations, unreadMessagesWorks)
{
    EXPECT_THAT(uut_->unreadMessages(emptyData_.id), Eq(0));
    EXPECT_THAT(uut_->unreadMessages(data_.id), Eq(1));

    EXPECT_THAT(uut_->unreadMessages(42), Eq(0));
}

K_TEST_F(ApiConversations, undoneMessagesWorks)
{
    EXPECT_THAT(uut_->undoneMessages(emptyData_.id), Eq(0));
    EXPECT_THAT(uut_->undoneMessages(data_.id), Eq(1));

    EXPECT_THAT(uut_->undoneMessages(42), Eq(0));
}

K_TEST_F(ApiConversations, latestMessageTimestampWorks)
{
    EXPECT_THAT(uut_->latestMessageTimestamp(emptyData_.id),
                Eq(Api::Conversations::emptyConversationTimestamp()));

    EXPECT_THAT(uut_->latestMessageTimestamp(data_.id),
                Eq(messageData_.dateReceived));

    EXPECT_THAT(uut_->latestMessageTimestamp(42),
                Not(Eq(messageData_.dateReceived)));
}

K_TEST_F(ApiConversations, idRangeWorks)
{
    for (auto convId : TEST_IDS_VALID)
    {
        EXPECT_NO_THROW(uut_->participants(convId));
        EXPECT_NO_THROW(uut_->totalMessages(convId));
        EXPECT_NO_THROW(uut_->unreadMessages(convId));
        EXPECT_NO_THROW(uut_->undoneMessages(convId));
        EXPECT_NO_THROW(uut_->latestMessageTimestamp(convId));
        EXPECT_NO_THROW(uut_->triggerRemoval(convId));
    }

    for (auto convId : TEST_IDS_INVALID)
    {
        EXPECT_ANY_THROW(uut_->participants(convId));
        EXPECT_ANY_THROW(uut_->totalMessages(convId));
        EXPECT_ANY_THROW(uut_->unreadMessages(convId));
        EXPECT_ANY_THROW(uut_->undoneMessages(convId));
        EXPECT_ANY_THROW(uut_->latestMessageTimestamp(convId));
        EXPECT_ANY_THROW(uut_->triggerRemoval(convId));
    }
}
