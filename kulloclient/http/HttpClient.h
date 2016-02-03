// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#pragma once

#include <boost/optional.hpp>
#include <cstdint>
#include <memory>

namespace Kullo { namespace Http {

class RequestListener;
class ResponseListener;
struct Request;
struct Response;

class HttpClient {
public:
    virtual ~HttpClient() {}

    /**
     * Synchronously send the given request.
     * Not thread-safe! Use a separate HttpClient instance per thread.
     *
     * * timeout is measured in milliseconds
     * * requestListener must be non-null if method is PATCH, POST or PUT
     * * responseListener may be null
     */
    virtual Response sendRequest(const Request & request, int64_t timeout, const std::shared_ptr<RequestListener> & requestListener, const std::shared_ptr<ResponseListener> & responseListener) = 0;
};

} }  // namespace Kullo::Http
