// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from syncer.djinni

#pragma once

#include "kulloclient/api/AttachmentsBlockDownloadProgress.h"
#include "kulloclient/api/SyncPhase.h"
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace Kullo { namespace Api {

/** Encodes a progress update during syncing. Unknown totals are set to 0. */
struct SyncProgress final {
    SyncPhase phase;
    /** inbox (unit: messages) */
    int64_t incomingMessagesProcessed;
    int64_t incomingMessagesTotal;
    int64_t incomingMessagesNew;
    int64_t incomingMessagesNewUnread;
    int64_t incomingMessagesModified;
    int64_t incomingMessagesDeleted;
    /** incoming attachments (unit: bytes) */
    int64_t incomingAttachmentsDownloadedBytes;
    int64_t incomingAttachmentsTotalBytes;
    std::unordered_map<int64_t, AttachmentsBlockDownloadProgress> incomingAttachments;
    /** outgoing messages + attachments (unit: uncompressed bytes) */
    int64_t outgoingMessagesUploadedBytes;
    int64_t outgoingMessagesTotalBytes;
    /** Run time of the current sync (unit: milliseconds) */
    int64_t runTimeMs;

    SyncProgress(SyncPhase phase_,
                 int64_t incomingMessagesProcessed_,
                 int64_t incomingMessagesTotal_,
                 int64_t incomingMessagesNew_,
                 int64_t incomingMessagesNewUnread_,
                 int64_t incomingMessagesModified_,
                 int64_t incomingMessagesDeleted_,
                 int64_t incomingAttachmentsDownloadedBytes_,
                 int64_t incomingAttachmentsTotalBytes_,
                 std::unordered_map<int64_t, AttachmentsBlockDownloadProgress> incomingAttachments_,
                 int64_t outgoingMessagesUploadedBytes_,
                 int64_t outgoingMessagesTotalBytes_,
                 int64_t runTimeMs_)
    : phase(std::move(phase_))
    , incomingMessagesProcessed(std::move(incomingMessagesProcessed_))
    , incomingMessagesTotal(std::move(incomingMessagesTotal_))
    , incomingMessagesNew(std::move(incomingMessagesNew_))
    , incomingMessagesNewUnread(std::move(incomingMessagesNewUnread_))
    , incomingMessagesModified(std::move(incomingMessagesModified_))
    , incomingMessagesDeleted(std::move(incomingMessagesDeleted_))
    , incomingAttachmentsDownloadedBytes(std::move(incomingAttachmentsDownloadedBytes_))
    , incomingAttachmentsTotalBytes(std::move(incomingAttachmentsTotalBytes_))
    , incomingAttachments(std::move(incomingAttachments_))
    , outgoingMessagesUploadedBytes(std::move(outgoingMessagesUploadedBytes_))
    , outgoingMessagesTotalBytes(std::move(outgoingMessagesTotalBytes_))
    , runTimeMs(std::move(runTimeMs_))
    {}
};

} }  // namespace Kullo::Api
