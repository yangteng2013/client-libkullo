// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from drafts.djinni

#include "DraftAttachments.h"  // my header
#include "AsyncTask.h"
#include "DraftAttachmentsAddListener.h"
#include "DraftAttachmentsContentListener.h"
#include "DraftAttachmentsSaveToListener.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

DraftAttachments::DraftAttachments() : ::djinni::JniInterface<::Kullo::Api::DraftAttachments, DraftAttachments>("net/kullo/libkullo/api/DraftAttachments$CppProxy") {}

DraftAttachments::~DraftAttachments() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::Kullo::Api::DraftAttachments>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1allForDraft(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->allForDraft(::djinni::I64::toCpp(jniEnv, j_convId));
        return ::djinni::release(::djinni::List<::djinni::I64>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1addAsync(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jstring j_path, jstring j_mimeType, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->addAsync(::djinni::I64::toCpp(jniEnv, j_convId),
                               ::djinni::String::toCpp(jniEnv, j_path),
                               ::djinni::String::toCpp(jniEnv, j_mimeType),
                               ::JNI::Kullo::Api::DraftAttachmentsAddListener::toCpp(jniEnv, j_listener));
        return ::djinni::release(::JNI::Kullo::Api::AsyncTask::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1remove(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        ref->remove(::djinni::I64::toCpp(jniEnv, j_convId),
                    ::djinni::I64::toCpp(jniEnv, j_attId));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1filename(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->filename(::djinni::I64::toCpp(jniEnv, j_convId),
                               ::djinni::I64::toCpp(jniEnv, j_attId));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1setFilename(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId, jstring j_filename)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        ref->setFilename(::djinni::I64::toCpp(jniEnv, j_convId),
                         ::djinni::I64::toCpp(jniEnv, j_attId),
                         ::djinni::String::toCpp(jniEnv, j_filename));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1mimeType(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->mimeType(::djinni::I64::toCpp(jniEnv, j_convId),
                               ::djinni::I64::toCpp(jniEnv, j_attId));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jlong JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1size(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->size(::djinni::I64::toCpp(jniEnv, j_convId),
                           ::djinni::I64::toCpp(jniEnv, j_attId));
        return ::djinni::release(::djinni::I64::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1hash(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->hash(::djinni::I64::toCpp(jniEnv, j_convId),
                           ::djinni::I64::toCpp(jniEnv, j_attId));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1contentAsync(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->contentAsync(::djinni::I64::toCpp(jniEnv, j_convId),
                                   ::djinni::I64::toCpp(jniEnv, j_attId),
                                   ::JNI::Kullo::Api::DraftAttachmentsContentListener::toCpp(jniEnv, j_listener));
        return ::djinni::release(::JNI::Kullo::Api::AsyncTask::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_DraftAttachments_00024CppProxy_native_1saveToAsync(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_convId, jlong j_attId, jstring j_path, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::DraftAttachments>(nativeRef);
        auto r = ref->saveToAsync(::djinni::I64::toCpp(jniEnv, j_convId),
                                  ::djinni::I64::toCpp(jniEnv, j_attId),
                                  ::djinni::String::toCpp(jniEnv, j_path),
                                  ::JNI::Kullo::Api::DraftAttachmentsSaveToListener::toCpp(jniEnv, j_listener));
        return ::djinni::release(::JNI::Kullo::Api::AsyncTask::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} } }  // namespace JNI::Kullo::Api
