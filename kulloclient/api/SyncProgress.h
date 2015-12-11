// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include <cstdint>
#include <utility>

namespace Kullo { namespace Api {

struct SyncProgress final {
    /** stats about messages */
    int64_t countLeft;
    int64_t countProcessed;
    int64_t countTotal;
    int64_t countNew;
    int64_t countNewUnread;
    int64_t countModified;
    int64_t countDeleted;
    /** Run time of the current sync in milliseconds */
    int64_t runTimeMs;

    SyncProgress(int64_t countLeft,
                 int64_t countProcessed,
                 int64_t countTotal,
                 int64_t countNew,
                 int64_t countNewUnread,
                 int64_t countModified,
                 int64_t countDeleted,
                 int64_t runTimeMs)
    : countLeft(std::move(countLeft))
    , countProcessed(std::move(countProcessed))
    , countTotal(std::move(countTotal))
    , countNew(std::move(countNew))
    , countNewUnread(std::move(countNewUnread))
    , countModified(std::move(countModified))
    , countDeleted(std::move(countDeleted))
    , runTimeMs(std::move(runTimeMs))
    {}
};

} }  // namespace Kullo::Api
