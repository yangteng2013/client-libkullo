// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from client.djinni

#include "ClientGenerateKeysListener.h"  // my header
#include "Registration.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

ClientGenerateKeysListener::ClientGenerateKeysListener() : ::djinni::JniInterface<::Kullo::Api::ClientGenerateKeysListener, ClientGenerateKeysListener>() {}

ClientGenerateKeysListener::~ClientGenerateKeysListener() = default;

ClientGenerateKeysListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

ClientGenerateKeysListener::JavaProxy::~JavaProxy() = default;

void ClientGenerateKeysListener::JavaProxy::progress(int8_t c_progress) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::JNI::Kullo::Api::ClientGenerateKeysListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_progress,
                           ::djinni::get(::djinni::I8::fromCpp(jniEnv, c_progress)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void ClientGenerateKeysListener::JavaProxy::finished(const std::shared_ptr<::Kullo::Api::Registration> & c_registration) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::JNI::Kullo::Api::ClientGenerateKeysListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_finished,
                           ::djinni::get(::JNI::Kullo::Api::Registration::fromCpp(jniEnv, c_registration)));
    ::djinni::jniExceptionCheck(jniEnv);
}

} } }  // namespace JNI::Kullo::Api
