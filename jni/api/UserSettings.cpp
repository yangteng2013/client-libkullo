// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from usersettings.djinni

#include "UserSettings.h"  // my header
#include "Address.h"
#include "DateTime.h"
#include "MasterKey.h"
#include "UserSettings.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

UserSettings::UserSettings() : ::djinni::JniInterface<::Kullo::Api::UserSettings, UserSettings>("net/kullo/libkullo/api/UserSettings$CppProxy") {}

UserSettings::~UserSettings() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Api::UserSettings>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_UserSettings_create(JNIEnv* jniEnv, jobject /*this*/, jobject j_address, jobject j_masterKey)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::Kullo::Api::UserSettings::create(::JNI::Kullo::Api::Address::toCpp(jniEnv, j_address),
                                                    ::JNI::Kullo::Api::MasterKey::toCpp(jniEnv, j_masterKey));
        return ::djinni::release(::JNI::Kullo::Api::UserSettings::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1address(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->address();
        return ::djinni::release(::JNI::Kullo::Api::Address::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1masterKey(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->masterKey();
        return ::djinni::release(::JNI::Kullo::Api::MasterKey::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1name(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->name();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setName(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_name)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setName(::djinni::String::toCpp(jniEnv, j_name));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1organization(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->organization();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setOrganization(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_organization)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setOrganization(::djinni::String::toCpp(jniEnv, j_organization));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1footer(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->footer();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setFooter(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_footer)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setFooter(::djinni::String::toCpp(jniEnv, j_footer));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1avatarMimeType(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->avatarMimeType();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setAvatarMimeType(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_mimeType)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setAvatarMimeType(::djinni::String::toCpp(jniEnv, j_mimeType));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jbyteArray JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1avatar(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->avatar();
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setAvatar(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_avatar)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setAvatar(::djinni::Binary::toCpp(jniEnv, j_avatar));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1keyBackupConfirmed(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->keyBackupConfirmed();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setKeyBackupConfirmed(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setKeyBackupConfirmed();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1keyBackupDontRemindBefore(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        auto r = ref->keyBackupDontRemindBefore();
        return ::djinni::release(::djinni::Optional<boost::optional, ::JNI::Kullo::Api::DateTime>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_api_UserSettings_00024CppProxy_native_1setKeyBackupDontRemindBefore(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_dontRemindBefore)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Kullo::Api::UserSettings>(nativeRef);
        ref->setKeyBackupDontRemindBefore(::djinni::Optional<boost::optional, ::JNI::Kullo::Api::DateTime>::toCpp(jniEnv, j_dontRemindBefore));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

} } }  // namespace JNI::Kullo::Api
