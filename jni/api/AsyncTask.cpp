// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from asynctask.djinni

#include "AsyncTask.h"  // my header
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

AsyncTask::AsyncTask() : ::djinni::JniInterface<::Kullo::Api::AsyncTask, AsyncTask>("net/kullo/libkullo/api/AsyncTask$CppProxy") {}

AsyncTask::~AsyncTask() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_AsyncTask_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Api::AsyncTask>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_AsyncTask_00024CppProxy_native_1cancel(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::AsyncTask>(nativeRef);
        ref->cancel();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_net_kullo_libkullo_api_AsyncTask_00024CppProxy_native_1isDone(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::AsyncTask>(nativeRef);
        auto r = ref->isDone();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_AsyncTask_00024CppProxy_native_1waitUntilDone(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::AsyncTask>(nativeRef);
        ref->waitUntilDone();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_net_kullo_libkullo_api_AsyncTask_00024CppProxy_native_1waitForMs(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_timeout)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::AsyncTask>(nativeRef);
        auto r = ref->waitForMs(::djinni::I32::toCpp(jniEnv, j_timeout));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Api
