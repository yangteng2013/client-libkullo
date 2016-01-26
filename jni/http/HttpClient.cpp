// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#include "HttpClient.h"  // my header
#include "Request.h"
#include "RequestListener.h"
#include "Response.h"
#include "ResponseListener.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Http {

HttpClient::HttpClient() : ::djinni::JniInterface<::Kullo::Http::HttpClient, HttpClient>() {}

HttpClient::~HttpClient() = default;

HttpClient::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

HttpClient::JavaProxy::~JavaProxy() = default;

::Kullo::Http::Response HttpClient::JavaProxy::sendRequest(const ::Kullo::Http::Request & c_request, int64_t c_timeout, const std::shared_ptr<::Kullo::Http::RequestListener> & c_requestListener, const std::shared_ptr<::Kullo::Http::ResponseListener> & c_responseListener) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::JNI::Kullo::Http::HttpClient>::get();
    auto jret = jniEnv->CallObjectMethod(Handle::get().get(), data.method_sendRequest,
                                         ::djinni::get(::JNI::Kullo::Http::Request::fromCpp(jniEnv, c_request)),
                                         ::djinni::get(::djinni::I64::fromCpp(jniEnv, c_timeout)),
                                         ::djinni::get(::JNI::Kullo::Http::RequestListener::fromCpp(jniEnv, c_requestListener)),
                                         ::djinni::get(::JNI::Kullo::Http::ResponseListener::fromCpp(jniEnv, c_responseListener)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::JNI::Kullo::Http::Response::toCpp(jniEnv, jret);
}

} } }  // namespace JNI::Kullo::Http
