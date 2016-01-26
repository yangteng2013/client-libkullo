// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from session.djinni

#pragma once

#include "kulloclient/api/EventType.h"
#include <cstdint>
#include <utility>

namespace Kullo { namespace Api {

struct Event final {
    EventType event;
    /** -1 if not applicable */
    int64_t conversationId;
    /** -1 if not applicable */
    int64_t messageId;
    /** -1 if not applicable */
    int64_t attachmentId;

    Event(EventType event_,
          int64_t conversationId_,
          int64_t messageId_,
          int64_t attachmentId_)
    : event(std::move(event_))
    , conversationId(std::move(conversationId_))
    , messageId(std::move(messageId_))
    , attachmentId(std::move(attachmentId_))
    {}
};

} }  // namespace Kullo::Api
