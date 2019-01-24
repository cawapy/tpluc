#pragma once

#include "Timespan.h"

template <
    typename latchPin,
    typename outputEnablePin,
    typename spi,
    typename tLatch = tpluc::TimespanUs<1>
>
class ShiftRegister595SpiConnected
{
public:

    static void Init()
    {
        latchPin::Enable(); latchPin::Set();
        outputEnablePin::Enable(); outputEnablePin::Set();
    }

    static void ShiftOut(uint8_t* values, uint8_t count)
    {
        spi::BeginTransfer(MSBFIRST, SPI_MODE0);
        spi::Transfer(values, count);
        spi::EndTransfer();
    }

    static void Latch()
    {
        latchPin::Clear();
        tLatch::Wait();
        latchPin::Set();
    }

    static void EnableOutputs() { outputEnablePin::Clear(); }
    static void DisableOutputs() { outputEnablePin::Set(); }
};
