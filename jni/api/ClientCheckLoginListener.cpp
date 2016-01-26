// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#include "ClientCheckLoginListener.h"  // my header
#include "Address.h"
#include "MasterKey.h"
#include "NetworkError.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

ClientCheckLoginListener::ClientCheckLoginListener() : ::djinni::JniInterface<::Kullo::Api::ClientCheckLoginListener, ClientCheckLoginListener>() {}

ClientCheckLoginListener::~ClientCheckLoginListener() = default;

ClientCheckLoginListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

ClientCheckLoginListener::JavaProxy::~JavaProxy() = default;

void ClientCheckLoginListener::JavaProxy::finished(const std::shared_ptr<::Kullo::Api::Address> & c_address, const std::shared_ptr<::Kullo::Api::MasterKey> & c_masterKey, bool c_valid) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::JNI::Kullo::Api::ClientCheckLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_finished,
                           ::djinni::get(::JNI::Kullo::Api::Address::fromCpp(jniEnv, c_address)),
                           ::djinni::get(::JNI::Kullo::Api::MasterKey::fromCpp(jniEnv, c_masterKey)),
                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c_valid)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void ClientCheckLoginListener::JavaProxy::error(const std::shared_ptr<::Kullo::Api::Address> & c_address, ::Kullo::Api::NetworkError c_error) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::JNI::Kullo::Api::ClientCheckLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_error,
                           ::djinni::get(::JNI::Kullo::Api::Address::fromCpp(jniEnv, c_address)),
                           ::djinni::get(::JNI::Kullo::Api::NetworkError::fromCpp(jniEnv, c_error)));
    ::djinni::jniExceptionCheck(jniEnv);
}

} } }  // namespace JNI::Kullo::Api
