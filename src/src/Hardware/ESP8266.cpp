/*
 * ESP8266.cpp
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#include "ESP8266.h"
#include <string>
#include "HW_USART.h"

namespace Hardware {

bool ESP8266::Reset(void){
  std::string resetString = "AT+RST\n";
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(resetString.c_str())), resetString.length());
  return true;
}
}


