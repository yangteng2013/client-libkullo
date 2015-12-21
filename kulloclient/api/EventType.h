// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include <functional>

namespace Kullo { namespace Api {

enum class EventType : int {
    ConversationAdded,
    ConversationChanged,
    ConversationRemoved,
    DraftStateChanged,
    DraftTextChanged,
    DraftAttachmentAdded,
    DraftAttachmentRemoved,
    MessageAdded,
    MessageDeliveryChanged,
    MessageStateChanged,
    MessageAttachmentsDownloadedChanged,
    MessageRemoved,
    LatestSenderChanged,
};

} }  // namespace Kullo::Api

namespace std {

template <>
struct hash<::Kullo::Api::EventType> {
    size_t operator()(::Kullo::Api::EventType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std