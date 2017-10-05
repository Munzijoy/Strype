/*
 * ESP8266.cpp
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#include "ESP8266.h"
#include "HW_USART.h"
#include "Wait.h"

namespace Hardware {

void ESP8266::SendCommand(std::string cmd){
  cmd.append("\r\r\n");
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitSec(2);
}

void ESP8266::Test(void){
  SendCommand("AT+GMR");
}
}


