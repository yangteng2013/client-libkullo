// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#include "Registry.h"  // my header
#include "HttpClientFactory.h"

namespace JNI { namespace Kullo { namespace Http {

Registry::Registry() : ::djinni::JniInterface<::Kullo::Http::Registry, Registry>("net/kullo/libkullo/http/Registry$CppProxy") {}

Registry::~Registry() = default;


CJNIEXPORT void JNICALL Java_net_kullo_libkullo_http_Registry_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::Kullo::Http::Registry>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_net_kullo_libkullo_http_Registry_setHttpClientFactory(JNIEnv* jniEnv, jobject /*this*/, jobject j_factory)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::Kullo::Http::Registry::setHttpClientFactory(::JNI::Kullo::Http::HttpClientFactory::toCpp(jniEnv, j_factory));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

} } }  // namespace JNI::Kullo::Http