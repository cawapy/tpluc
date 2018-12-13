#pragma once

#include <Arduino.h>

namespace tpluc
{
    namespace ArduinoApi
    {
        template<uint32_t ms> struct TimespanMs { static void Wait() { delay(ms); } };
        template<uint32_t us> struct TimespanUs { static void Wait() { delayMicroseconds(us); } };
    }
}

