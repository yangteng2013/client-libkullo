// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from senders.djinni

#include "Senders.h"  // my header
#include "Address.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

Senders::Senders() : ::djinni::JniInterface<::Kullo::Api::Senders, Senders>("net/kullo/libkullo/api/Senders$CppProxy") {}

Senders::~Senders() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Senders_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::Kullo::Api::Senders>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_Senders_00024CppProxy_native_1name(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_msgId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Senders>(nativeRef);
        auto r = ref->name(::djinni::I64::toCpp(jniEnv, j_msgId));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_Senders_00024CppProxy_native_1address(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_msgId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Senders>(nativeRef);
        auto r = ref->address(::djinni::I64::toCpp(jniEnv, j_msgId));
        return ::djinni::release(::djinni::Optional<boost::optional, ::JNI::Kullo::Api::Address>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_Senders_00024CppProxy_native_1organization(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_msgId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Senders>(nativeRef);
        auto r = ref->organization(::djinni::I64::toCpp(jniEnv, j_msgId));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_Senders_00024CppProxy_native_1avatarMimeType(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_msgId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Senders>(nativeRef);
        auto r = ref->avatarMimeType(::djinni::I64::toCpp(jniEnv, j_msgId));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_net_kullo_libkullo_api_Senders_00024CppProxy_native_1avatar(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_msgId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Senders>(nativeRef);
        auto r = ref->avatar(::djinni::I64::toCpp(jniEnv, j_msgId));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Api
