#pragma once

namespace tpluc
{
    template<uint32_t ms> struct TimespanMs
    {
        static const bool IsZero = ms == 0;
        static void Wait() { _delay_ms(ms); }
    };

    template<uint32_t us> struct TimespanUs
    {
        static const bool IsZero = us == 0;
        static void Wait() { _delay_us(us); }
    };

    struct TimespanZero
    {
        static const bool IsZero = true;
        static void Wait() { }
    };
}

