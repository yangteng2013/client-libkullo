// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include <cstdint>
#include <utility>
class DateTime; // Requiring extended class

namespace Kullo { namespace Api {

struct DateTimeBase {
    int16_t year;
    int8_t month;
    int8_t day;
    int8_t hour;
    int8_t minute;
    int8_t second;
    int16_t tzOffsetMinutes;

    DateTimeBase(int16_t year,
                 int8_t month,
                 int8_t day,
                 int8_t hour,
                 int8_t minute,
                 int8_t second,
                 int16_t tzOffsetMinutes)
    : year(std::move(year))
    , month(std::move(month))
    , day(std::move(day))
    , hour(std::move(hour))
    , minute(std::move(minute))
    , second(std::move(second))
    , tzOffsetMinutes(std::move(tzOffsetMinutes))
    {}

    virtual ~DateTimeBase() = default;

protected:
    DateTimeBase(const DateTimeBase&) = default;
#if !defined(_MSC_VER) || _MSC_VER > 1900
    DateTimeBase(DateTimeBase&&) = default;
#endif
    DateTimeBase& operator=(const DateTimeBase&) = default;
#if !defined(_MSC_VER) || _MSC_VER > 1900
    DateTimeBase& operator=(DateTimeBase&&) = default;
#endif
};

} }  // namespace Kullo::Api