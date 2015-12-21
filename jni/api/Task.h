// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/Task.h"

namespace JNI { namespace Kullo { namespace Api {

class Task final : ::djinni::JniInterface<::Kullo::Api::Task, Task> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::Task>;
    using JniType = jobject;

    using Boxed = Task;

    ~Task();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Task>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return {jniEnv, ::djinni::JniClass<Task>::get()._toJava(jniEnv, c)}; }

private:
    Task();
    friend ::djinni::JniClass<Task>;
    friend ::djinni::JniInterface<::Kullo::Api::Task, Task>;

};

} } }  // namespace JNI::Kullo::Api