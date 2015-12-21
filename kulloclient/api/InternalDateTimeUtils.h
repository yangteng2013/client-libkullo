// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "kulloclient/api/DateTime.h"
#include <cstdint>
#include <string>

namespace Kullo { namespace Api {

class InternalDateTimeUtils {
public:
    virtual ~InternalDateTimeUtils() {}

    /** Checks a set of DateTime constructor arguments for validity */
    static bool isValid(int16_t year, int8_t month, int8_t day, int8_t hour, int8_t minute, int8_t second, int16_t tzOffsetMinutes);

    /** Returns the current time in the UTC timezone */
    static DateTime nowUtc();

    /**
     * Returns the RFC3339 representation
     * yyyy-mm-ddThh:mm:ss[.f+](Z|(+|-)hh:mm) (case-insensitive)
     */
    static std::string toString(const DateTime & dateTime);

    /**
     * Compares two DateTime objects, taking time zones etc. into account.
     * Returns -1 iff lhs < rhs, 0 iff lhs == rhs, 1 iff lhs > rhs.
     */
    static int8_t compare(const DateTime & lhs, const DateTime & rhs);
};

} }  // namespace Kullo::Api