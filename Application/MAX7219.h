/*
 * MAX7219.h
 *
 *  Created on: ???
 *      Author: t.linz
 */

#ifndef MAX7219_H
#define MAX7219_H

#include <stdint.h>
#include <vector>

#include "LedWrapper.h"
#include "LookupTable.h"
#include "mbed.h"

namespace Driver {
    
    class MAX7219 {
        friend class Application::LedWrapper;
        friend class Application::Lookuptable;
        private:
            enum eRegisterMap {
              eNoOp = 0,
              eDigit0 = 1,
              eDigit1 = 2,
              eDigit2 = 3,
              eDigit3 = 4,
              eDigit4 = 5,
              eDigit5 = 6,
              eDigit6 = 7,
              eDigit7 = 8,

              eDecodeMode = 9,
              eIntensity = 10,
              eScanLimit = 11,
              eShutdown = 12,
              eDisplayTest = 15
            };
            
            enum eSegments {
                eSegDP = 0x80,
                eSegA  = 0x40,
                eSegB  = 0x20,
                eSegC  = 0x10,
                eSegD  = 0x08,
                eSegE  = 0x04,
                eSegF  = 0x02,
                eSegG  = 0x01,
            };
            
            enum ShutdownModes {
              eShutdownMode = 0x0000,
              eNormalOperationMode = 0x0001
            };
             
            MAX7219(uint8_t numberInDaisyChain) : _u8NumberInDaisyChain(numberInDaisyChain){ }
            static void WriteDataToBus(unsigned short data);
            static void SendDataToAddress(uint8_t u8Address, uint8_t u8Data, uint8_t u8Num);
            static void SendDataBlock(const char* pData, const uint8_t u8Address);
            static void Send32Bit(uint32_t u32Data, const uint8_t u8Address);
            static MAX7219* GetMax7219ByNumber(uint8_t u8Number);
            static inline uint16_t DataAndAdressToBusData(uint8_t u8Data, uint8_t u8Address){
              return static_cast<uint16_t>((u8Address << 8) | u8Data);
            }
            
            void SetOrClearBitForDigit(uint8_t u8Digit, uint8_t u8Bit, bool bOn);
            uint8_t GetValueForDigit(uint8_t u8Digit);
            void ClearLEDs(void);
            void Init(void);
            
            static const uint8_t NUM_MAX7219_IN_DAISY_CHAIN = 8;
            static const uint8_t NUM_DIGITS = 8;
            static const std::vector<MAX7219*> _pMAX7219Vector;
            
            const uint8_t _u8NumberInDaisyChain;
            static uint8_t _aBusData[NUM_MAX7219_IN_DAISY_CHAIN][NUM_DIGITS];
            
            static uint32_t _aPixel[NUM_DIGITS];
            
            static SPI _spiHardware;
            static DigitalOut _cs;

};
}
//extern bool gDebugNow;

#endif
