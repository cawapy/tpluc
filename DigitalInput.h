#pragma once

namespace tpluc
{
    template<uint8_t portNo> struct PortBDigitalInput
    {
        static const uint8_t bit = 1 << portNo;
        static void Init() { DDRB &= ~bit; }
        static bool Read() { return PINB & bit; }
    };

    template<uint8_t portNo> struct PortCDigitalInput
    {
        static const uint8_t bit = 1 << portNo;
        static void Init() { DDRC &= ~bit; }
        static bool Read() { return PINC & bit; }
    };

    template<uint8_t portNo> struct PortDDigitalInput
    {
        static const uint8_t bit = 1 << portNo;
        static void Init() { DDRD &= ~bit; }
        static bool Read() { return PIND & bit; }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalInput {};

        template<> struct DigitalInput< 0> : public PortDDigitalInput<PD0> {};
        template<> struct DigitalInput< 1> : public PortDDigitalInput<PD1> {};
        template<> struct DigitalInput< 2> : public PortDDigitalInput<PD2> {};
        template<> struct DigitalInput< 3> : public PortDDigitalInput<PD3> {};
        template<> struct DigitalInput< 4> : public PortDDigitalInput<PD4> {};
        template<> struct DigitalInput< 5> : public PortDDigitalInput<PD5> {};
        template<> struct DigitalInput< 6> : public PortDDigitalInput<PD6> {};
        template<> struct DigitalInput< 7> : public PortDDigitalInput<PD7> {};

        template<> struct DigitalInput< 8> : public PortBDigitalInput<PB0> {};
        template<> struct DigitalInput< 9> : public PortBDigitalInput<PB1> {};
        template<> struct DigitalInput<10> : public PortBDigitalInput<PB2> {};
        template<> struct DigitalInput<11> : public PortBDigitalInput<PB3> {};
        template<> struct DigitalInput<12> : public PortBDigitalInput<PB4> {};
        template<> struct DigitalInput<13> : public PortBDigitalInput<PB5> {};
    }
}

