#pragma once

#include <Arduino.h>

namespace tpluc
{
    namespace ArduinoApi
    {
        template<uint8_t pin> struct DigitalOutput
        {
            static void Enable() { pinMode(pin, OUTPUT); }
            static void Disable() { pinMode(pin, INPUT); }
            static void Set() { digitalWrite(pin, HIGH); }
            static void Clear() { digitalWrite(pin, LOW); }
        };
    }
}
