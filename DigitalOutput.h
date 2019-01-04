#pragma once

namespace tpluc
{
    template<uint8_t portNo> struct PortBDigitalOutput
    {
        static const uint8_t bit = 1 << portNo;
        static void Enable() { DDRB |= bit; }
        static void Disable() { DDRB &= ~bit; }
        static void Set() { PORTB |= bit; }
        static void Clear() { PORTB &= ~bit; }
    };

    template<uint8_t portNo> struct PortCDigitalOutput
    {
        static const uint8_t bit = 1 << portNo;
        static void Enable() { DDRC |= bit; }
        static void Disable() { DDRC &= ~bit; }
        static void Set() { PORTC |= bit; }
        static void Clear() { PORTC &= ~bit; }
    };

    template<uint8_t portNo> struct PortDDigitalOutput
    {
        static const uint8_t bit = 1 << portNo;
        static void Enable() { DDRD |= bit; }
        static void Disable() { DDRD &= ~bit; }
        static void Set() { PORTD |= bit; }
        static void Clear() { PORTD &= ~bit; }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalOutput {};

        template<> struct DigitalOutput< 0> : public PortDDigitalOutput<PD0> {};
        template<> struct DigitalOutput< 1> : public PortDDigitalOutput<PD1> {};
        template<> struct DigitalOutput< 2> : public PortDDigitalOutput<PD2> {};
        template<> struct DigitalOutput< 3> : public PortDDigitalOutput<PD3> {};
        template<> struct DigitalOutput< 4> : public PortDDigitalOutput<PD4> {};
        template<> struct DigitalOutput< 5> : public PortDDigitalOutput<PD5> {};
        template<> struct DigitalOutput< 6> : public PortDDigitalOutput<PD6> {};
        template<> struct DigitalOutput< 7> : public PortDDigitalOutput<PD7> {};

        template<> struct DigitalOutput< 8> : public PortBDigitalOutput<PB0> {};
        template<> struct DigitalOutput< 9> : public PortBDigitalOutput<PB1> {};
        template<> struct DigitalOutput<10> : public PortBDigitalOutput<PB2> {};
        template<> struct DigitalOutput<11> : public PortBDigitalOutput<PB3> {};
        template<> struct DigitalOutput<12> : public PortBDigitalOutput<PB4> {};
        template<> struct DigitalOutput<13> : public PortBDigitalOutput<PB5> {};
    }
}
