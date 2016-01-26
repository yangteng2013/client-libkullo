// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from taskrunner.djinni

#include "Task.h"  // my header

namespace JNI { namespace Kullo { namespace Api {

Task::Task() : ::djinni::JniInterface<::Kullo::Api::Task, Task>("net/kullo/libkullo/api/Task$CppProxy") {}

Task::~Task() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Task_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Api::Task>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Task_00024CppProxy_native_1run(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Task>(nativeRef);
        ref->run();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

} } }  // namespace JNI::Kullo::Api
