// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/http/HttpClientFactory.h"

namespace JNI { namespace Kullo { namespace Http {

class HttpClientFactory final : ::djinni::JniInterface<::Kullo::Http::HttpClientFactory, HttpClientFactory> {
public:
    using CppType = std::shared_ptr<::Kullo::Http::HttpClientFactory>;
    using CppOptType = std::shared_ptr<::Kullo::Http::HttpClientFactory>;
    using JniType = jobject;

    using Boxed = HttpClientFactory;

    ~HttpClientFactory();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<HttpClientFactory>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<HttpClientFactory>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    HttpClientFactory();
    friend ::djinni::JniClass<HttpClientFactory>;
    friend ::djinni::JniInterface<::Kullo::Http::HttpClientFactory, HttpClientFactory>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::Kullo::Http::HttpClientFactory
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::shared_ptr<::Kullo::Http::HttpClient> createHttpClient() override;
        std::unordered_map<std::string, std::string> versions() override;

    private:
        friend ::djinni::JniInterface<::Kullo::Http::HttpClientFactory, ::JNI::Kullo::Http::HttpClientFactory>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("net/kullo/libkullo/http/HttpClientFactory") };
    const jmethodID method_createHttpClient { ::djinni::jniGetMethodID(clazz.get(), "createHttpClient", "()Lnet/kullo/libkullo/http/HttpClient;") };
    const jmethodID method_versions { ::djinni::jniGetMethodID(clazz.get(), "versions", "()Ljava/util/HashMap;") };
};

} } }  // namespace JNI::Kullo::Http
