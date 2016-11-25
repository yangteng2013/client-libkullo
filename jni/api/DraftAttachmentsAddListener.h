// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from drafts.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/DraftAttachmentsAddListener.h"

namespace JNI { namespace Kullo { namespace Api {

class DraftAttachmentsAddListener final : ::djinni::JniInterface<::Kullo::Api::DraftAttachmentsAddListener, DraftAttachmentsAddListener> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::DraftAttachmentsAddListener>;
    using CppOptType = std::shared_ptr<::Kullo::Api::DraftAttachmentsAddListener>;
    using JniType = jobject;

    using Boxed = DraftAttachmentsAddListener;

    ~DraftAttachmentsAddListener();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<DraftAttachmentsAddListener>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<DraftAttachmentsAddListener>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    DraftAttachmentsAddListener();
    friend ::djinni::JniClass<DraftAttachmentsAddListener>;
    friend ::djinni::JniInterface<::Kullo::Api::DraftAttachmentsAddListener, DraftAttachmentsAddListener>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::Kullo::Api::DraftAttachmentsAddListener
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void progressed(int64_t convId, int64_t attId, int64_t bytesProcessed, int64_t bytesTotal) override;
        void finished(int64_t convId, int64_t attId, const std::string & path) override;
        void error(int64_t convId, const std::string & path, ::Kullo::Api::LocalError error) override;

    private:
        friend ::djinni::JniInterface<::Kullo::Api::DraftAttachmentsAddListener, ::JNI::Kullo::Api::DraftAttachmentsAddListener>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("net/kullo/libkullo/api/DraftAttachmentsAddListener") };
    const jmethodID method_progressed { ::djinni::jniGetMethodID(clazz.get(), "progressed", "(JJJJ)V") };
    const jmethodID method_finished { ::djinni::jniGetMethodID(clazz.get(), "finished", "(JJLjava/lang/String;)V") };
    const jmethodID method_error { ::djinni::jniGetMethodID(clazz.get(), "error", "(JLjava/lang/String;Lnet/kullo/libkullo/api/LocalError;)V") };
};

} } }  // namespace JNI::Kullo::Api
