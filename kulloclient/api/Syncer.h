// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from syncer.djinni

#pragma once

#include <cstdint>
#include <memory>

namespace Kullo { namespace Api {

class AsyncTask;
class SyncerListener;
enum class SyncMode;

/**
 * Handles syncing, including downloading of attachments. Prevents multiple syncs
 * from running in parallel by building a queue and intelligently merging sync
 * requests.
 * Examples: Enqueuing a WithoutAttachments sync removes a SendOnly sync from the
 * queue. A running SendOnly sync would be cancelled. Enqueuing a SendOnly sync
 * while a WithoutAttachments sync is running or enqueued will do nothing.
 * Enqueuing an Everything sync will remove all attachment download requests from
 * the queue.
 */
class Syncer {
public:
    virtual ~Syncer() {}

    /** Set or replace the SyncerListener which should receive sync events. */
    virtual void setListener(const std::shared_ptr<SyncerListener> & listener) = 0;

    /** Request that the data specified in mode is synced. */
    virtual void requestSync(SyncMode mode) = 0;

    /** Request that all attachments for the given message are downloaded. */
    virtual void requestDownloadingAttachmentsForMessage(int64_t msgId) = 0;

    /**
     * Gets an AsyncTask that can be used for cancellation or waiting. It affects
     * both running and queued jobs. Releasing it will not cancel the job
     * automatically.
     */
    virtual std::shared_ptr<AsyncTask> asyncTask() = 0;
};

} }  // namespace Kullo::Api
