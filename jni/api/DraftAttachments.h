// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from drafts.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/DraftAttachments.h"

namespace JNI { namespace Kullo { namespace Api {

class DraftAttachments final : ::djinni::JniInterface<::Kullo::Api::DraftAttachments, DraftAttachments> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::DraftAttachments>;
    using CppOptType = std::shared_ptr<::Kullo::Api::DraftAttachments>;
    using JniType = jobject;

    using Boxed = DraftAttachments;

    ~DraftAttachments();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<DraftAttachments>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<DraftAttachments>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    DraftAttachments();
    friend ::djinni::JniClass<DraftAttachments>;
    friend ::djinni::JniInterface<::Kullo::Api::DraftAttachments, DraftAttachments>;

};

} } }  // namespace JNI::Kullo::Api
