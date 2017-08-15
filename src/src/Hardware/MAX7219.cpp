/*
 * MAX7219.cpp
 *
 *  Created on: ???
 *      Author: t.linz
 */

#include "MAX7219.h"
#include "stm32f10x_gpio.h"
#include "Develop.h"
#include "HW_SPI.h"
#include <stdlib.h>
#include <assert.h>
#include <Wait.h>
#include "diag/Trace.h"

bool gDebugNow = false;

namespace Driver {
    
const std::vector<MAX7219*> MAX7219::_pMAX7219Vector = { 
    new Driver::MAX7219(0), new Driver::MAX7219(1), new Driver::MAX7219(2), new Driver::MAX7219(3)
};



uint8_t MAX7219::_aBusData[NUM_MAX7219_IN_DAISY_CHAIN][NUM_DIGITS] = {0, 0};
uint32_t MAX7219::_aPixel[NUM_DIGITS] = {0, 0, 0, 0, 0, 0, 0, 0};
    
void Delay(uint32_t nCount){
  for(; nCount != 0; nCount--){
    nCount = nCount;
  }
}

// hardware initialization (sets each ic to default values (includes display test in develop mode)
void MAX7219::Init(void){
#if LED_TEST
//jedes IC kurz in den Testmodus versetzen und Testmodus wieder deaktivieren (-> Blinken)
    for (uint8_t num = 0; num < DISPLAY_TEST_DURATION; num++){
        SendDataToAddress(eDisplayTest, num % 2, _u8NumberInDaisyChain);
        Tools::Timing::WaitMs(40);
    }
#endif
    SendDataToAddress(eDisplayTest, 0, _u8NumberInDaisyChain);
    SendDataToAddress(eShutdown, eNormalOperationMode, _u8NumberInDaisyChain);
    SendDataToAddress(eDecodeMode, 0, _u8NumberInDaisyChain);
    SendDataToAddress(eScanLimit, 7, _u8NumberInDaisyChain);
    SendDataToAddress(eIntensity, 0x0F, _u8NumberInDaisyChain);
    ClearLEDs();

#if LED_TEST
    for (uint16_t j = 1; j <= 8; j++){
      for (uint16_t i = 0; i < 9 ; i++){
        if (i == 8){
          SendDataToAddress(j, static_cast<uint8_t>(0), _u8NumberInDaisyChain);
        } else {
          SendDataToAddress(j, static_cast<uint8_t>(1 << i), _u8NumberInDaisyChain);
        }
        Tools::Timing::WaitMs(5);
      }
    }
        
    ClearLEDs();
#endif
}

void MAX7219::ClearLEDs(void){
    for (uint8_t address = 0; address < NUM_DIGITS; address++){
        SendDataToAddress(address + 1, 0, _u8NumberInDaisyChain);
    }
}

void MAX7219::SendDataBlock(const char* pData, const uint8_t u8Address){
    for (uint8_t address = 0; address < NUM_DIGITS; address++){
      GetMax7219ByNumber(u8Address)->SendDataToAddress(address + 1, pData[address], u8Address);
    }
}

void MAX7219::Send32Bit(uint32_t u32Data, const uint8_t u8Address){
  for (auto pDriver : _pMAX7219Vector){
    pDriver->SendDataToAddress(
        u8Address,
        static_cast<uint8_t>((u32Data & (0xFF << (8*(pDriver->_u8NumberInDaisyChain)))) >> (8*pDriver->_u8NumberInDaisyChain)),
        pDriver->_u8NumberInDaisyChain);
  }
}

// writes the content of data to the device register for the num device in the daisy chain
void MAX7219::SendDataToAddress(uint8_t u8Address, uint8_t u8Data, uint8_t u8Num){
    assert(u8Num < NUM_MAX7219_IN_DAISY_CHAIN);
              
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
    Delay(500);
    
    for (uint8_t i = 0; i < (NUM_MAX7219_IN_DAISY_CHAIN - 1) - u8Num; i++){
        WriteDataToBus(DataAndAdressToBusData(0xFF, eNoOp));
    }
    
    WriteDataToBus(DataAndAdressToBusData(u8Data, u8Address));
    
    if ((u8Address >= 1) && (u8Address <= NUM_DIGITS)){
      _aBusData[u8Num][u8Address - 1] = u8Data;
    }
    
    for (uint8_t i = 0; i < u8Num; i++){
        WriteDataToBus(DataAndAdressToBusData(0xFF, eNoOp));
    }
    
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
    Delay(500);
}

// returns the driver object corresponding to the daisy chain number
MAX7219* MAX7219::GetMax7219ByNumber(uint8_t u8Number){ 
    assert(u8Number < NUM_MAX7219_IN_DAISY_CHAIN);

    if (u8Number < _pMAX7219Vector.size()){
        return _pMAX7219Vector[u8Number];
    } else { 
        throw std::exception();
    } 
}

// writes data to the spi bus
void MAX7219::WriteDataToBus(uint16_t data){
    (void)Hardware::HW_SPI::Transmit16Bit(data);
    Delay(50);
}
}
