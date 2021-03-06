// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from syncer.djinni

#include "AttachmentsBlockDownloadProgress.h"  // my header
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

AttachmentsBlockDownloadProgress::AttachmentsBlockDownloadProgress() = default;

AttachmentsBlockDownloadProgress::~AttachmentsBlockDownloadProgress() = default;

auto AttachmentsBlockDownloadProgress::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<AttachmentsBlockDownloadProgress>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.downloadedBytes)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.totalBytes)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto AttachmentsBlockDownloadProgress::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<AttachmentsBlockDownloadProgress>::get();
    return {::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_downloadedBytes)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_totalBytes))};
}

} } }  // namespace JNI::Kullo::Api
