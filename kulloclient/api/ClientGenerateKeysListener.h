// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from client.djinni

#pragma once

#include <cstdint>
#include <memory>

namespace Kullo { namespace Api {

class Registration;

/** Listener used in Client.generateKeysAsync() */
class ClientGenerateKeysListener {
public:
    virtual ~ClientGenerateKeysListener() {}

    /** Progress of key generation, in percent. */
    virtual void progress(int8_t progress) = 0;

    /**
     * Called when key generation is done. Use registration to register an
     * account.
     */
    virtual void finished(const std::shared_ptr<Registration> & registration) = 0;
};

} }  // namespace Kullo::Api
