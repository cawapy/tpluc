#pragma once

#include <SPI.h>

#include "Frequency.h"

namespace tpluc
{
    namespace ArduinoApi
    {
        template <typename frequency = FrequencyMHz<8>>
        struct Spi
        {
            static void Init()
            {
                SPI.begin();
            }

            static void BeginTransfer(uint8_t bitOrder, uint8_t dataMode)
            {
                SPI.beginTransaction(SPISettings(frequency::Hz, bitOrder, dataMode));
            }

            static void EndTransfer()
            {
                SPI.endTransaction();
            }

            static void Transfer(void* buff, size_t count)
            {
                SPI.transfer(buff, count);
            }

            static uint8_t Transfer(uint8_t data)
            {
                return SPI.transfer(data);
            }

            static uint16_t Transfer16(uint16_t data)
            {
                return SPI.transfer16(data);
            }
        };
    }
}
