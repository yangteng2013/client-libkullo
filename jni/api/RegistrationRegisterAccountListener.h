// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from registration.djinni

#pragma once

#include "jni/support-lib/jni/djinni_support.hpp"
#include "kulloclient/api/RegistrationRegisterAccountListener.h"

namespace JNI { namespace Kullo { namespace Api {

class RegistrationRegisterAccountListener final : ::djinni::JniInterface<::Kullo::Api::RegistrationRegisterAccountListener, RegistrationRegisterAccountListener> {
public:
    using CppType = std::shared_ptr<::Kullo::Api::RegistrationRegisterAccountListener>;
    using CppOptType = std::shared_ptr<::Kullo::Api::RegistrationRegisterAccountListener>;
    using JniType = jobject;

    using Boxed = RegistrationRegisterAccountListener;

    ~RegistrationRegisterAccountListener();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<RegistrationRegisterAccountListener>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<RegistrationRegisterAccountListener>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    RegistrationRegisterAccountListener();
    friend ::djinni::JniClass<RegistrationRegisterAccountListener>;
    friend ::djinni::JniInterface<::Kullo::Api::RegistrationRegisterAccountListener, RegistrationRegisterAccountListener>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::Kullo::Api::RegistrationRegisterAccountListener
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void challengeNeeded(const std::shared_ptr<::Kullo::Api::Address> & address, const std::shared_ptr<::Kullo::Api::Challenge> & challenge) override;
        void addressNotAvailable(const std::shared_ptr<::Kullo::Api::Address> & address, ::Kullo::Api::AddressNotAvailableReason reason) override;
        void finished(const std::shared_ptr<::Kullo::Api::Address> & address, const std::shared_ptr<::Kullo::Api::MasterKey> & masterKey) override;
        void error(const std::shared_ptr<::Kullo::Api::Address> & address, ::Kullo::Api::NetworkError error) override;

    private:
        friend ::djinni::JniInterface<::Kullo::Api::RegistrationRegisterAccountListener, ::JNI::Kullo::Api::RegistrationRegisterAccountListener>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("net/kullo/libkullo/api/RegistrationRegisterAccountListener") };
    const jmethodID method_challengeNeeded { ::djinni::jniGetMethodID(clazz.get(), "challengeNeeded", "(Lnet/kullo/libkullo/api/Address;Lnet/kullo/libkullo/api/Challenge;)V") };
    const jmethodID method_addressNotAvailable { ::djinni::jniGetMethodID(clazz.get(), "addressNotAvailable", "(Lnet/kullo/libkullo/api/Address;Lnet/kullo/libkullo/api/AddressNotAvailableReason;)V") };
    const jmethodID method_finished { ::djinni::jniGetMethodID(clazz.get(), "finished", "(Lnet/kullo/libkullo/api/Address;Lnet/kullo/libkullo/api/MasterKey;)V") };
    const jmethodID method_error { ::djinni::jniGetMethodID(clazz.get(), "error", "(Lnet/kullo/libkullo/api/Address;Lnet/kullo/libkullo/api/NetworkError;)V") };
};

} } }  // namespace JNI::Kullo::Api
