// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#include "RequestListener.h"  // my header
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Http {

RequestListener::RequestListener() : ::djinni::JniInterface<::Kullo::Http::RequestListener, RequestListener>("net/kullo/libkullo/http/RequestListener$CppProxy") {}

RequestListener::~RequestListener() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_http_RequestListener_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::Kullo::Http::RequestListener>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jbyteArray JNICALL Java_net_kullo_libkullo_http_RequestListener_00024CppProxy_native_1read(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_maxSize)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Http::RequestListener>(nativeRef);
        auto r = ref->read(::djinni::I64::toCpp(jniEnv, j_maxSize));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Http
