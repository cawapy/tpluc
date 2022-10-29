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

    template<uint8_t portNo, uint8_t noBits> struct PortBDigitalOutputRange
    {
        static const uint8_t bits = ((0b11111111 >> (8-noBits)) << portNo) ;
        static void Enable() { DDRB |= bits; }
        static void Disable() { DDRB &= ~bits; }
        static void Set() { PORTB |= bits; }
        static void Clear() { PORTB &= ~bits; }
        static void Assign(uint8_t val) { PORTB = (PORTB & ~bits) | ((val << portNo) & bits); }
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

    template<uint8_t portNo, uint8_t noBits> struct PortDDigitalOutputRange
    {
        static const uint8_t bits = ((0b11111111 >> (8-noBits)) << portNo) ;
        static void Enable() { DDRD |= bits; }
        static void Disable() { DDRD &= ~bits; }
        static void Set() { PORTD |= bits; }
        static void Clear() { PORTD &= ~bits; }
        static void Assign(uint8_t val) { PORTD = (PORTD & ~bits) | ((val << portNo) & bits); }
    };

    namespace Arduino
    {
        template<uint8_t arduinoPinNumber> class DigitalOutput {};
        template<uint8_t arduinoPinNumber, uint8_t numberBits> class DigitalOutputRange {};

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

        template<uint8_t n> struct DigitalOutputRange< 0, n> : public PortDDigitalOutputRange<PD0, n> {};
        template<uint8_t n> struct DigitalOutputRange< 1, n> : public PortDDigitalOutputRange<PD1, n> {};
        template<uint8_t n> struct DigitalOutputRange< 2, n> : public PortDDigitalOutputRange<PD2, n> {};
        template<uint8_t n> struct DigitalOutputRange< 3, n> : public PortDDigitalOutputRange<PD3, n> {};
        template<uint8_t n> struct DigitalOutputRange< 4, n> : public PortDDigitalOutputRange<PD4, n> {};
        template<uint8_t n> struct DigitalOutputRange< 5, n> : public PortDDigitalOutputRange<PD5, n> {};
        template<uint8_t n> struct DigitalOutputRange< 6, n> : public PortDDigitalOutputRange<PD6, n> {};

        template<uint8_t n> struct DigitalOutputRange< 8, n> : public PortBDigitalOutputRange<PB0, n> {};
        template<uint8_t n> struct DigitalOutputRange< 9, n> : public PortBDigitalOutputRange<PB1, n> {};
        template<uint8_t n> struct DigitalOutputRange<10, n> : public PortBDigitalOutputRange<PB2, n> {};
        template<uint8_t n> struct DigitalOutputRange<11, n> : public PortBDigitalOutputRange<PB3, n> {};
        template<uint8_t n> struct DigitalOutputRange<12, n> : public PortBDigitalOutputRange<PB4, n> {};
    }
}
