/*
 * LedWrapper.cpp
 *
 *  Created on: 08.11.2016
 *      Author: t.linz
 */
 
#include <stdlib.h>
#include <stm32f10x_rtc.h>
#include <list>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <string.h>
#include "diag/Trace.h"

#include "LedWrapper.h"
#include "MAX7219.h"
#include "Delay.h"

namespace Application {

constexpr char LedWrapper::font8x8_basic[256][8];

void LedWrapper::DisplayString(std::string stringToDisplay, uint16_t delay){
  const auto length = stringToDisplay.length();
  assert(length > 0);
  char letterA[8];
  char letterB[8];
  char letterC[8];
  char letterD[8];
  char letterE[8];
  uint64_t text[8];
  uint8_t counter = 4;
  
  do {
    memcpy(letterA, font8x8_basic[stringToDisplay[counter - 4]], 8 * sizeof(char));
    
    if (length > 1){
      memcpy(letterB, font8x8_basic[stringToDisplay[counter - 3]], 8 * sizeof(char));
    }
    
    if (length > 2){
      memcpy(letterC, font8x8_basic[stringToDisplay[counter - 2]], 8 * sizeof(char));
    }
    
    if (length > 3){
      memcpy(letterD, font8x8_basic[stringToDisplay[counter - 1]], 8 * sizeof(char));
    }
    
    if (length > 4){
      memcpy(letterE, font8x8_basic[stringToDisplay[counter - 0]], 8 * sizeof(char));
    }
    
    uint8_t doShift = (length >  Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN) ? 8 : 1; 
    for (uint8_t shift = 0; shift < doShift; shift++){
      for (uint8_t i = 0; i < 8; i++){
         text[i] = (letterA[i] << (0 * 8));
         if (length > 1){ text[i] |= (letterB[i] << (1 * 8)); }
         if (length > 2){ text[i] |= (letterC[i] << (2 * 8)); }
         if (length > 3){ text[i] |= (letterD[i] << (3 * 8)); }
         if (length > 4){ text[i] |= (static_cast<uint64_t>(letterE[i]) << (4 * 8)); }
         text[i] >>= shift;
         
         Driver::MAX7219::Send32Bit(static_cast<uint32_t>(text[i]), 8 - i);
      }
      ((shift == 0) && (counter == 4)) ? Tools::Timing::WaitMs(1000) : Tools::Timing::WaitMs(delay);
    }
    
    counter++;
  } while (counter < length);

  trace_printf("Tom has not implemented %s yet\n", __PRETTY_FUNCTION__);
}

// must be called after initializing the hardware and before using the wrapper 
void LedWrapper::InitLedWrapper(void){
    for (auto iter = Driver::MAX7219::_pMAX7219Vector.begin(); iter != Driver::MAX7219::_pMAX7219Vector.end(); iter++){
      trace_printf("%s: Init Nr. %d von %d\n", __PRETTY_FUNCTION__, (*iter)->_u8NumberInDaisyChain + 1, Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN);
      (*iter)->Init();
    }
}

// clears alls leds connected to every single max7219 ic
void LedWrapper::ClearPanel(void){
    for (auto iter = Driver::MAX7219::_pMAX7219Vector.begin(); iter != Driver::MAX7219::_pMAX7219Vector.end(); iter++){
        (*iter)->ClearLEDs();
    }
}
}
