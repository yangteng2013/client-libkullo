// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from address.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/Address.h"

namespace JNI { namespace Kullo { namespace Api {

class Address final : ::djinni::JniInterface<::Kullo::Api::Address, Address> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::Address>;
    using CppOptType = std::shared_ptr<::Kullo::Api::Address>;
    using JniType = jobject;

    using Boxed = Address;

    ~Address();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Address>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Address>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Address();
    friend ::djinni::JniClass<Address>;
    friend ::djinni::JniInterface<::Kullo::Api::Address, Address>;

};

} } }  // namespace JNI::Kullo::Api
