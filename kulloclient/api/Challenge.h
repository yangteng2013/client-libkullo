// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "kulloclient/api/ChallengeType.h"
#include <string>

namespace Kullo { namespace Api {

class Challenge {
public:
    virtual ~Challenge() {}

    virtual ChallengeType type() = 0;

    virtual std::string text() = 0;
};

} }  // namespace Kullo::Api