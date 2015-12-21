// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/http/HttpClient.h"

namespace JNI { namespace Kullo { namespace Http {

class HttpClient final : ::djinni::JniInterface<::Kullo::Http::HttpClient, HttpClient> {
public:
    using CppType = std::shared_ptr<::Kullo::Http::HttpClient>;
    using JniType = jobject;

    using Boxed = HttpClient;

    ~HttpClient();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<HttpClient>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return {jniEnv, ::djinni::JniClass<HttpClient>::get()._toJava(jniEnv, c)}; }

private:
    HttpClient();
    friend ::djinni::JniClass<HttpClient>;
    friend ::djinni::JniInterface<::Kullo::Http::HttpClient, HttpClient>;

    class JavaProxy final : ::djinni::JavaProxyCacheEntry, public ::Kullo::Http::HttpClient
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        ::Kullo::Http::Response sendRequest(const ::Kullo::Http::Request & request, int64_t timeout, const std::shared_ptr<::Kullo::Http::RequestListener> & requestListener, const std::shared_ptr<::Kullo::Http::ResponseListener> & responseListener) override;

    private:
        using ::djinni::JavaProxyCacheEntry::getGlobalRef;
        friend ::djinni::JniInterface<::Kullo::Http::HttpClient, ::JNI::Kullo::Http::HttpClient>;
        friend ::djinni::JavaProxyCache<JavaProxy>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("net/kullo/libkullo/http/HttpClient") };
    const jmethodID method_sendRequest { ::djinni::jniGetMethodID(clazz.get(), "sendRequest", "(Lnet/kullo/libkullo/http/Request;JLnet/kullo/libkullo/http/RequestListener;Lnet/kullo/libkullo/http/ResponseListener;)Lnet/kullo/libkullo/http/Response;") };
};

} } }  // namespace JNI::Kullo::Http