#pragma once

#include "DigitalInput.h"

namespace tpluc
{
    template<uint8_t pin> struct PortBDigitalInputPullup : public PortBDigitalInput<pin>
    {
        static void Init() { DDRB &= ~PortBDigitalInput<pin>::bit; PORTB |= PortBDigitalInput<pin>::bit; }
    };

    template<uint8_t pin> struct PortCDigitalInputPullup : public PortCDigitalInput<pin>
    {
        static void Init() { DDRC &= ~PortCDigitalInput<pin>::bit; PORTC |= PortCDigitalInput<pin>::bit; }
    };

    template<uint8_t pin> struct PortDDigitalInputPullup : public PortDDigitalInput<pin>
    {
        static void Init() { DDRD &= ~PortDDigitalInput<pin>::bit; PORTD |= PortDDigitalInput<pin>::bit; }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalInputPullup {};

        template<> struct DigitalInputPullup< 0> : public PortDDigitalInputPullup<0> {};
        template<> struct DigitalInputPullup< 1> : public PortDDigitalInputPullup<1> {};
        template<> struct DigitalInputPullup< 2> : public PortDDigitalInputPullup<2> {};
        template<> struct DigitalInputPullup< 3> : public PortDDigitalInputPullup<3> {};
        template<> struct DigitalInputPullup< 4> : public PortDDigitalInputPullup<4> {};
        template<> struct DigitalInputPullup< 5> : public PortDDigitalInputPullup<5> {};
        template<> struct DigitalInputPullup< 6> : public PortDDigitalInputPullup<6> {};
        template<> struct DigitalInputPullup< 7> : public PortDDigitalInputPullup<7> {};

        template<> struct DigitalInputPullup< 8> : public PortBDigitalInputPullup<0> {};
        template<> struct DigitalInputPullup< 9> : public PortBDigitalInputPullup<1> {};
        template<> struct DigitalInputPullup<10> : public PortBDigitalInputPullup<2> {};
        template<> struct DigitalInputPullup<11> : public PortBDigitalInputPullup<3> {};
        template<> struct DigitalInputPullup<12> : public PortBDigitalInputPullup<4> {};
        template<> struct DigitalInputPullup<13> : public PortBDigitalInputPullup<5> {};
    }
}

