#pragma once

namespace tpluc
{
    template<uint8_t pin> struct PortBDigitalOutput
    {
        static const uint8_t bit = 1 << pin;
        static void Enable() { DDRB |= bit; }
        static void Disable() { DDRB &= ~bit; }
        static void Set() { PORTB |= bit; }
        static void Clear() { PORTB &= ~bit; }
    };

    template<uint8_t pin> struct PortCDigitalOutput
    {
        static const uint8_t bit = 1 << pin;
        static void Enable() { DDRC |= bit; }
        static void Disable() { DDRC &= ~bit; }
        static void Set() { PORTC |= bit; }
        static void Clear() { PORTC &= ~bit; }
    };

    template<uint8_t pin> struct PortDDigitalOutput
    {
        static const uint8_t bit = 1 << pin;
        static void Enable() { DDRD |= bit; }
        static void Disable() { DDRD &= ~bit; }
        static void Set() { PORTD |= bit; }
        static void Clear() { PORTD &= ~bit; }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalOutput {};

        template<> struct DigitalOutput< 0> : public PortDDigitalOutput<0> {};
        template<> struct DigitalOutput< 1> : public PortDDigitalOutput<1> {};
        template<> struct DigitalOutput< 2> : public PortDDigitalOutput<2> {};
        template<> struct DigitalOutput< 3> : public PortDDigitalOutput<3> {};
        template<> struct DigitalOutput< 4> : public PortDDigitalOutput<4> {};
        template<> struct DigitalOutput< 5> : public PortDDigitalOutput<5> {};
        template<> struct DigitalOutput< 6> : public PortDDigitalOutput<6> {};
        template<> struct DigitalOutput< 7> : public PortDDigitalOutput<7> {};

        template<> struct DigitalOutput< 8> : public PortBDigitalOutput<0> {};
        template<> struct DigitalOutput< 9> : public PortBDigitalOutput<1> {};
        template<> struct DigitalOutput<10> : public PortBDigitalOutput<2> {};
        template<> struct DigitalOutput<11> : public PortBDigitalOutput<3> {};
        template<> struct DigitalOutput<12> : public PortBDigitalOutput<4> {};
        template<> struct DigitalOutput<13> : public PortBDigitalOutput<5> {};
    }
}
