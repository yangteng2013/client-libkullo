// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#include "Delivery.h"  // my header
#include "Address.h"
#include "DateTime.h"
#include "DeliveryReason.h"
#include "DeliveryState.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

Delivery::Delivery() : ::djinni::JniInterface<::Kullo::Api::Delivery, Delivery>("net/kullo/libkullo/api/Delivery$CppProxy") {}

Delivery::~Delivery() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Delivery_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Api::Delivery>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_Delivery_00024CppProxy_native_1recipient(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::CppProxyHandle<::Kullo::Api::Delivery>::get(nativeRef);
        auto r = ref->recipient();
        return ::djinni::release(::JNI::Kullo::Api::Address::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_Delivery_00024CppProxy_native_1state(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::CppProxyHandle<::Kullo::Api::Delivery>::get(nativeRef);
        auto r = ref->state();
        return ::djinni::release(::JNI::Kullo::Api::DeliveryState::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_Delivery_00024CppProxy_native_1reason(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::CppProxyHandle<::Kullo::Api::Delivery>::get(nativeRef);
        auto r = ref->reason();
        return ::djinni::release(::djinni::Optional<boost::optional, ::JNI::Kullo::Api::DeliveryReason>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_Delivery_00024CppProxy_native_1date(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::CppProxyHandle<::Kullo::Api::Delivery>::get(nativeRef);
        auto r = ref->date();
        return ::djinni::release(::djinni::Optional<boost::optional, ::JNI::Kullo::Api::DateTime>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Api