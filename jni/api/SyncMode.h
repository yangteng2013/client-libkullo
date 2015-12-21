// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/SyncMode.h"

namespace JNI { namespace Kullo { namespace Api {

class SyncMode final : ::djinni::JniEnum {
public:
    using CppType = ::Kullo::Api::SyncMode;
    using JniType = jobject;

    using Boxed = SyncMode;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<SyncMode>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<SyncMode>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    SyncMode() : JniEnum("net/kullo/libkullo/api/SyncMode") {}
    friend ::djinni::JniClass<SyncMode>;
};

} } }  // namespace JNI::Kullo::Api