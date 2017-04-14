// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from syncer.djinni

#pragma once

#include <cstdint>
#include <utility>

namespace Kullo { namespace Api {

/** A block of attachments from a single message */
struct AttachmentsBlockDownloadProgress final {
    int64_t downloadedBytes;
    int64_t totalBytes;

    AttachmentsBlockDownloadProgress(int64_t downloadedBytes_,
                                     int64_t totalBytes_)
    : downloadedBytes(std::move(downloadedBytes_))
    , totalBytes(std::move(totalBytes_))
    {}
};

} }  // namespace Kullo::Api
