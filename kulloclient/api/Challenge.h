// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from registration.djinni

#pragma once

#include <string>

namespace Kullo { namespace Api {

enum class ChallengeType;

class Challenge {
public:
    virtual ~Challenge() {}

    virtual ChallengeType type() = 0;

    virtual std::string text() = 0;
};

} }  // namespace Kullo::Api
