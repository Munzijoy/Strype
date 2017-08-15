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
#include <Wait.h>
#include "diag/Trace.h"

#include "LedWrapper.h"
#include "MAX7219.h"

namespace Application {

constexpr char LedWrapper::font8x8_basic[128 - FONT_OFFSET][8];

void LedWrapper::DisplayString(std::string stringToDisplay, uint16_t delay){
  const auto length = stringToDisplay.length();
  assert(length > 0);
  char letter[Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN + 1][8];
  uint32_t text[8][(Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN / 8) + 2];
  uint8_t counter = Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN;
  
  do {
   for (uint8_t driver = 0; driver < Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN + 1; driver++){
      memcpy(letter[driver], Get8x8Character(static_cast<uint8_t>(stringToDisplay[counter - (Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN  - driver)])), 8 * sizeof(char));
    }
    
    uint8_t doShift = (length >  Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN) ? 8 : 1; 
    for (uint8_t shift = 0; shift < doShift; shift++){
      for (uint8_t digit = 0; digit < Driver::MAX7219::NUM_DIGITS; digit++){
        memset(&text, 0, sizeof(text));
        for (uint8_t letterNum = 0; letterNum < Driver::MAX7219::NUM_MAX7219_IN_DAISY_CHAIN + 1; letterNum++){
          if (length > letterNum){
              text[digit][letterNum >> 2] |= (letter[letterNum][digit] << ((letterNum - (4*(letterNum >> 2))) * 8));
          }
        }
        
        uint64_t test = (static_cast<uint64_t>(text[digit][1]) << 32ULL) | text[digit][0];
        test >>= shift;
         
         Driver::MAX7219::Send32Bit(static_cast<uint32_t>(test), 8 - digit);
      }
      ((shift == 0) && (counter == 4)) ? Tools::Wait::WaitSec(1) : Tools::Wait::WaitMs(delay);
    }
    
    counter++;
  } while (counter < length);
  
  Tools::Wait::WaitSec(1);
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
