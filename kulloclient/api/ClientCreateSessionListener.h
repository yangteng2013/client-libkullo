// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "kulloclient/api/LocalError.h"
#include <memory>

namespace Kullo { namespace Api {

class Address;
class Session;

/** Listener used in Client.createSessionAsync() */
class ClientCreateSessionListener {
public:
    virtual ~ClientCreateSessionListener() {}

    virtual void finished(const std::shared_ptr<Session> & session) = 0;

    virtual void error(const std::shared_ptr<Address> & address, LocalError error) = 0;
};

} }  // namespace Kullo::Api