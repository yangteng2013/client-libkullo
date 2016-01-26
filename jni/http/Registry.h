// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/http/Registry.h"

namespace JNI { namespace Kullo { namespace Http {

class Registry final : ::djinni::JniInterface<::Kullo::Http::Registry, Registry> {
public:
    using CppType = std::shared_ptr<::Kullo::Http::Registry>;
    using CppOptType = std::shared_ptr<::Kullo::Http::Registry>;
    using JniType = jobject;

    using Boxed = Registry;

    ~Registry();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Registry>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Registry>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Registry();
    friend ::djinni::JniClass<Registry>;
    friend ::djinni::JniInterface<::Kullo::Http::Registry, Registry>;

};

} } }  // namespace JNI::Kullo::Http
