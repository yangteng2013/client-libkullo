/* Copyright 2013–2017 Kullo GmbH. All rights reserved. */
#include "kulloclient/api_impl/usersettingsimpl.h"

#include "kulloclient/api/Address.h"
#include "kulloclient/api/MasterKey.h"
#include "kulloclient/api_impl/DateTime.h"
#include "kulloclient/util/assert.h"
#include "kulloclient/util/kulloaddress.h"
#include "kulloclient/util/masterkey.h"
#include "kulloclient/util/usersettings.h"

namespace Kullo {
namespace ApiImpl {

UserSettingsImpl::UserSettingsImpl(
        const Db::SharedSessionPtr &dbSession,
        const Util::Credentials &credentials)
    : userSettings_(Util::UserSettings(credentials))
    , dao_(dbSession)
{
    dao_.load(userSettings_);
}

std::shared_ptr<Api::Address> UserSettingsImpl::address()
{
    return Api::Address::create(userSettings_.credentials.address->toString());
}

std::shared_ptr<Api::MasterKey> UserSettingsImpl::masterKey()
{
    return Api::MasterKey::createFromDataBlocks(
                userSettings_.credentials.masterKey->dataBlocks());
}

std::string UserSettingsImpl::name()
{
    return userSettings_.name;
}

void UserSettingsImpl::setName(const std::string &name)
{
    userSettings_.name = name;
    dao_.setName(name);
}

std::string UserSettingsImpl::organization()
{
    return userSettings_.organization;
}

void UserSettingsImpl::setOrganization(const std::string &organization)
{
    userSettings_.organization = organization;
    dao_.setOrganization(organization);
}

std::string UserSettingsImpl::footer()
{
    return userSettings_.footer;
}

void UserSettingsImpl::setFooter(const std::string &footer)
{
    userSettings_.footer = footer;
    dao_.setFooter(footer);
}

std::string UserSettingsImpl::avatarMimeType()
{
    return userSettings_.avatarMimeType;
}

void UserSettingsImpl::setAvatarMimeType(const std::string &mimeType)
{
    userSettings_.avatarMimeType = mimeType;
    dao_.setAvatarMimeType(mimeType);
}

std::vector<uint8_t> UserSettingsImpl::avatar()
{
    return userSettings_.avatarData;
}

void UserSettingsImpl::setAvatar(const std::vector<uint8_t> &avatar)
{
    userSettings_.avatarData = avatar;
    dao_.setAvatarData(avatar);
}

boost::optional<Api::DateTime> UserSettingsImpl::nextMasterKeyBackupReminder()
{
    if (!userSettings_.nextMasterKeyBackupReminder) return boost::none;

    const auto &dt = *userSettings_.nextMasterKeyBackupReminder;
    return Api::DateTime(
                dt.year(), dt.month(), dt.day(),
                dt.hour(), dt.minute(), dt.second(),
                dt.tzOffsetMinutes());
}

void UserSettingsImpl::setNextMasterKeyBackupReminder(
        const boost::optional<Api::DateTime> &reminderDate)
{
    if (!reminderDate)
    {
        userSettings_.nextMasterKeyBackupReminder = boost::none;
        dao_.setNextMasterKeyBackupReminder(boost::none);
        return;
    }

    auto &date = *reminderDate;
    Util::DateTime result{
        date.year, date.month, date.day,
        date.hour, date.minute, date.second,
        date.tzOffsetMinutes
    };
    userSettings_.nextMasterKeyBackupReminder = result;
    dao_.setNextMasterKeyBackupReminder(result);
}

Event::ApiEvents UserSettingsImpl::userSettingModified(const std::string &key)
{
    dao_.load(userSettings_, key);
    return {{}};
}

Util::UserSettings UserSettingsImpl::userSettings() const
{
    return userSettings_;
}

}
}
