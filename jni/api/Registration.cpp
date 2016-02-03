// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from registration.djinni

#include "Registration.h"  // my header
#include "Address.h"
#include "AsyncTask.h"
#include "Challenge.h"
#include "RegistrationRegisterAccountListener.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

Registration::Registration() : ::djinni::JniInterface<::Kullo::Api::Registration, Registration>("net/kullo/libkullo/api/Registration$CppProxy") {}

Registration::~Registration() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_Registration_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Api::Registration>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_Registration_00024CppProxy_native_1registerAccountAsync(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_address, jobject j_challenge, jstring j_challengeAnswer, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::Registration>(nativeRef);
        auto r = ref->registerAccountAsync(::JNI::Kullo::Api::Address::toCpp(jniEnv, j_address),
                                           ::djinni::Optional<boost::optional, ::JNI::Kullo::Api::Challenge>::toCpp(jniEnv, j_challenge),
                                           ::djinni::String::toCpp(jniEnv, j_challengeAnswer),
                                           ::JNI::Kullo::Api::RegistrationRegisterAccountListener::toCpp(jniEnv, j_listener));
        return ::djinni::release(::JNI::Kullo::Api::AsyncTask::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Api
