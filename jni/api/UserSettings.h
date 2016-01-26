// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from usersettings.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/UserSettings.h"

namespace JNI { namespace Kullo { namespace Api {

class UserSettings final : ::djinni::JniInterface<::Kullo::Api::UserSettings, UserSettings> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::UserSettings>;
    using CppOptType = std::shared_ptr<::Kullo::Api::UserSettings>;
    using JniType = jobject;

    using Boxed = UserSettings;

    ~UserSettings();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<UserSettings>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<UserSettings>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    UserSettings();
    friend ::djinni::JniClass<UserSettings>;
    friend ::djinni::JniInterface<::Kullo::Api::UserSettings, UserSettings>;

};

} } }  // namespace JNI::Kullo::Api
