// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from messages.djinni

#include "MessageAttachmentsContentListener.h"  // my header
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

MessageAttachmentsContentListener::MessageAttachmentsContentListener() : ::djinni::JniInterface<::Kullo::Api::MessageAttachmentsContentListener, MessageAttachmentsContentListener>() {}

MessageAttachmentsContentListener::~MessageAttachmentsContentListener() = default;

MessageAttachmentsContentListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

MessageAttachmentsContentListener::JavaProxy::~JavaProxy() = default;

void MessageAttachmentsContentListener::JavaProxy::finished(int64_t c_msgId, int64_t c_attId, const std::vector<uint8_t> & c_content) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::JNI::Kullo::Api::MessageAttachmentsContentListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_finished,
                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c_msgId)),
                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c_attId)),
                           ::djinni::get(::djinni::Binary::fromCpp(jniEnv, c_content)));
    ::djinni::jniExceptionCheck(jniEnv);
}

} } }  // namespace JNI::Kullo::Api
