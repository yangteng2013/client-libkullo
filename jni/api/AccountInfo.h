// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/AccountInfo.h"

namespace JNI { namespace Kullo { namespace Api {

class AccountInfo final {
public:
    using CppType = ::Kullo::Api::AccountInfo;
    using JniType = jobject;

    using Boxed = AccountInfo;

    ~AccountInfo();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    AccountInfo();
    friend ::djinni::JniClass<AccountInfo>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("net/kullo/libkullo/api/AccountInfo") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;)V") };
    const jfieldID field_settingsUrl { ::djinni::jniGetFieldID(clazz.get(), "settingsUrl", "Ljava/lang/String;") };
};

} } }  // namespace JNI::Kullo::Api