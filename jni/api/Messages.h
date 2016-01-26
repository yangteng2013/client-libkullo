// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from messages.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/Messages.h"

namespace JNI { namespace Kullo { namespace Api {

class Messages final : ::djinni::JniInterface<::Kullo::Api::Messages, Messages> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::Messages>;
    using CppOptType = std::shared_ptr<::Kullo::Api::Messages>;
    using JniType = jobject;

    using Boxed = Messages;

    ~Messages();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Messages>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Messages>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Messages();
    friend ::djinni::JniClass<Messages>;
    friend ::djinni::JniInterface<::Kullo::Api::Messages, Messages>;

};

} } }  // namespace JNI::Kullo::Api
