// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include <functional>

namespace Kullo { namespace Api {

enum class NetworkError : int {
    /** Client too old or otherwise blocked; should check for update */
    Forbidden,
    /** Client and server protocol incompatible; should check for update */
    Protocol,
    /** Bad login info (address + master key) */
    Unauthorized,
    /** Server-side error */
    Server,
    /** Network connection couldn't be established */
    Connection,
    /** Any other error */
    Unknown,
};

} }  // namespace Kullo::Api

namespace std {

template <>
struct hash<::Kullo::Api::NetworkError> {
    size_t operator()(::Kullo::Api::NetworkError type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std