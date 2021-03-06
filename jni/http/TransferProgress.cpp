// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#include "TransferProgress.h"  // my header
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Http {

TransferProgress::TransferProgress() = default;

TransferProgress::~TransferProgress() = default;

auto TransferProgress::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<TransferProgress>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.uploadTransferred)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.uploadTotal)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.downloadTransferred)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.downloadTotal)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto TransferProgress::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<TransferProgress>::get();
    return {::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_uploadTransferred)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_uploadTotal)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_downloadTransferred)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_downloadTotal))};
}

} } }  // namespace JNI::Kullo::Http
