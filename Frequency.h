#pragma once

namespace tpluc
{
    template <uint32_t n> struct FrequencyMHz { static const uint32_t Hz = n * 1000000ul; };
    template <uint32_t n> struct FrequencykHz { static const uint32_t Hz = n * 1000ul;    };
    template <uint32_t n> struct FrequencyHz  { static const uint32_t Hz = n;             };
}
