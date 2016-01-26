// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from masterkey.djinni

#include "MasterKey.h"  // my header
#include "MasterKey.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

MasterKey::MasterKey() : ::djinni::JniInterface<::Kullo::Api::MasterKey, MasterKey>("net/kullo/libkullo/api/MasterKey$CppProxy") {}

MasterKey::~MasterKey() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_MasterKey_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Api::MasterKey>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_MasterKey_createFromPem(JNIEnv* jniEnv, jobject /*this*/, jstring j_pem)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::Kullo::Api::MasterKey::createFromPem(::djinni::String::toCpp(jniEnv, j_pem));
        return ::djinni::release(::JNI::Kullo::Api::MasterKey::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_MasterKey_createFromDataBlocks(JNIEnv* jniEnv, jobject /*this*/, jobject j_dataBlocks)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::Kullo::Api::MasterKey::createFromDataBlocks(::djinni::List<::djinni::String>::toCpp(jniEnv, j_dataBlocks));
        return ::djinni::release(::JNI::Kullo::Api::MasterKey::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_net_kullo_libkullo_api_MasterKey_isValidBlock(JNIEnv* jniEnv, jobject /*this*/, jstring j_block)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::Kullo::Api::MasterKey::isValidBlock(::djinni::String::toCpp(jniEnv, j_block));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_MasterKey_00024CppProxy_native_1pem(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::MasterKey>(nativeRef);
        auto r = ref->pem();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_MasterKey_00024CppProxy_native_1dataBlocks(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::MasterKey>(nativeRef);
        auto r = ref->dataBlocks();
        return ::djinni::release(::djinni::List<::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_net_kullo_libkullo_api_MasterKey_00024CppProxy_native_1isEqualTo(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_other)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::MasterKey>(nativeRef);
        auto r = ref->isEqualTo(::JNI::Kullo::Api::MasterKey::toCpp(jniEnv, j_other));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Api
