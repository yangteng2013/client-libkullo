// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from registration.djinni

#pragma once

#include <boost/optional.hpp>
#include <memory>
#include <string>

namespace Kullo { namespace Api {

class Address;
class AsyncTask;
class Challenge;
class RegistrationRegisterAccountListener;

/** Can be obtained through Client.generateKeysAsync(). */
class Registration {
public:
    virtual ~Registration() {}

    /**
     * Register a new account.
     *
     * Set challenge to the value passed to
     * RegistrationRegisterAccountListener::challengeNeeded if you recently sent
     * a registration request for the same address that failed because of a
     * missing or wrong challenge answer. Otherwise, just pass null.
     *
     * If no challenge is needed, set challengeAnswer to ""
     */
    virtual std::shared_ptr<AsyncTask> registerAccountAsync(const std::shared_ptr<Address> & address, const std::shared_ptr<Challenge> & challenge, const std::string & challengeAnswer, const std::shared_ptr<RegistrationRegisterAccountListener> & listener) = 0;
};

} }  // namespace Kullo::Api
