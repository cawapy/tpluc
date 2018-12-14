#pragma once

namespace tpluc
{
    template<uint8_t pin> struct PortBDigitalInput
    {
        static const uint8_t bit = 1 << pin;
        static void Init() { DDRB &= ~bit; }
        static bool Read() { return PINB & bit; }
    };

    template<uint8_t pin> struct PortCDigitalInput
    {
        static const uint8_t bit = 1 << pin;
        static void Init() { DDRC &= ~bit; }
        static bool Read() { return PINC & bit; }
    };

    template<uint8_t pin> struct PortDDigitalInput
    {
        static const uint8_t bit = 1 << pin;
        static void Init() { DDRD &= ~bit; }
        static bool Read() { return PIND & bit; }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalInput {};

        template<> struct DigitalInput< 0> : public PortDDigitalInput<0> {};
        template<> struct DigitalInput< 1> : public PortDDigitalInput<1> {};
        template<> struct DigitalInput< 2> : public PortDDigitalInput<2> {};
        template<> struct DigitalInput< 3> : public PortDDigitalInput<3> {};
        template<> struct DigitalInput< 4> : public PortDDigitalInput<4> {};
        template<> struct DigitalInput< 5> : public PortDDigitalInput<5> {};
        template<> struct DigitalInput< 6> : public PortDDigitalInput<6> {};
        template<> struct DigitalInput< 7> : public PortDDigitalInput<7> {};

        template<> struct DigitalInput< 8> : public PortBDigitalInput<0> {};
        template<> struct DigitalInput< 9> : public PortBDigitalInput<1> {};
        template<> struct DigitalInput<10> : public PortBDigitalInput<2> {};
        template<> struct DigitalInput<11> : public PortBDigitalInput<3> {};
        template<> struct DigitalInput<12> : public PortBDigitalInput<4> {};
        template<> struct DigitalInput<13> : public PortBDigitalInput<5> {};
    }
}

