#pragma once

namespace tpluc
{
    template<uint32_t ms> struct TimespanMs { static void Wait() { _delay_ms(ms); } };
    template<uint32_t us> struct TimespanUs { static void Wait() { _delay_us(us); } };
}

