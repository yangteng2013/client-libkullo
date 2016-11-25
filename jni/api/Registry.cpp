// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from registry.djinni

#include "Registry.h"  // my header
#include "LogListener.h"
#include "TaskRunner.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

Registry::Registry() : ::djinni::JniInterface<::Kullo::Api::Registry, Registry>("net/kullo/libkullo/api/Registry$CppProxy") {}

Registry::~Registry() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Registry_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::Kullo::Api::Registry>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Registry_setLogListener(JNIEnv* jniEnv, jobject /*this*/, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::Kullo::Api::Registry::setLogListener(::djinni::Optional<boost::optional, ::JNI::Kullo::Api::LogListener>::toCpp(jniEnv, j_listener));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Registry_setTaskRunner(JNIEnv* jniEnv, jobject /*this*/, jobject j_taskRunner)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::Kullo::Api::Registry::setTaskRunner(::JNI::Kullo::Api::TaskRunner::toCpp(jniEnv, j_taskRunner));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

} } }  // namespace JNI::Kullo::Api
