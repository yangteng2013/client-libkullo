// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from messages.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/MessageAttachmentsContentListener.h"

namespace JNI { namespace Kullo { namespace Api {

class MessageAttachmentsContentListener final : ::djinni::JniInterface<::Kullo::Api::MessageAttachmentsContentListener, MessageAttachmentsContentListener> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::MessageAttachmentsContentListener>;
    using CppOptType = std::shared_ptr<::Kullo::Api::MessageAttachmentsContentListener>;
    using JniType = jobject;

    using Boxed = MessageAttachmentsContentListener;

    ~MessageAttachmentsContentListener();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<MessageAttachmentsContentListener>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<MessageAttachmentsContentListener>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    MessageAttachmentsContentListener();
    friend ::djinni::JniClass<MessageAttachmentsContentListener>;
    friend ::djinni::JniInterface<::Kullo::Api::MessageAttachmentsContentListener, MessageAttachmentsContentListener>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::Kullo::Api::MessageAttachmentsContentListener
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void finished(int64_t msgId, int64_t attId, const std::vector<uint8_t> & content) override;

    private:
        friend ::djinni::JniInterface<::Kullo::Api::MessageAttachmentsContentListener, ::JNI::Kullo::Api::MessageAttachmentsContentListener>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("net/kullo/libkullo/api/MessageAttachmentsContentListener") };
    const jmethodID method_finished { ::djinni::jniGetMethodID(clazz.get(), "finished", "(JJ[B)V") };
};

} } }  // namespace JNI::Kullo::Api
