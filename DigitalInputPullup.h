#pragma once

#include "DigitalInput.h"

namespace tpluc
{
    template<uint8_t portNo> struct PortBDigitalInputPullup : public PortBDigitalInput<portNo>
    {
        static void Init() { DDRB &= ~PortBDigitalInput<portNo>::bit; PORTB |= PortBDigitalInput<portNo>::bit; }
    };

    template<uint8_t portNo> struct PortCDigitalInputPullup : public PortCDigitalInput<portNo>
    {
        static void Init() { DDRC &= ~PortCDigitalInput<portNo>::bit; PORTC |= PortCDigitalInput<portNo>::bit; }
    };

    template<uint8_t portNo> struct PortDDigitalInputPullup : public PortDDigitalInput<portNo>
    {
        static void Init() { DDRD &= ~PortDDigitalInput<portNo>::bit; PORTD |= PortDDigitalInput<portNo>::bit; }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalInputPullup {};

        template<> struct DigitalInputPullup< 0> : public PortDDigitalInputPullup<PD0> {};
        template<> struct DigitalInputPullup< 1> : public PortDDigitalInputPullup<PD1> {};
        template<> struct DigitalInputPullup< 2> : public PortDDigitalInputPullup<PD2> {};
        template<> struct DigitalInputPullup< 3> : public PortDDigitalInputPullup<PD3> {};
        template<> struct DigitalInputPullup< 4> : public PortDDigitalInputPullup<PD4> {};
        template<> struct DigitalInputPullup< 5> : public PortDDigitalInputPullup<PD5> {};
        template<> struct DigitalInputPullup< 6> : public PortDDigitalInputPullup<PD6> {};
        template<> struct DigitalInputPullup< 7> : public PortDDigitalInputPullup<PD7> {};

        template<> struct DigitalInputPullup< 8> : public PortBDigitalInputPullup<PB0> {};
        template<> struct DigitalInputPullup< 9> : public PortBDigitalInputPullup<PB1> {};
        template<> struct DigitalInputPullup<10> : public PortBDigitalInputPullup<PB2> {};
        template<> struct DigitalInputPullup<11> : public PortBDigitalInputPullup<PB3> {};
        template<> struct DigitalInputPullup<12> : public PortBDigitalInputPullup<PB4> {};
        template<> struct DigitalInputPullup<13> : public PortBDigitalInputPullup<PB5> {};
    }
}

