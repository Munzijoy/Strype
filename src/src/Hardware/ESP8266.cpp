/*
 * ESP8266.cpp
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#include <MyESP8266.h>
#include "HW_USART.h"
#include "diag/Trace.h"
#include "diag/Trace.h"
#include <stdlib.h>

namespace Hardware {

ESP8266::eResponse ESP8266::m_eResponse(NOT_RESPONDING);
Tools::Wait ESP8266::m_TimeoutTimer(0);
volatile std::string ESP8266::m_UsartRxString("");

void ESP8266::SendCommand(std::string cmd, uint32_t waitMsAfterSending){
  trace_printf("Sending AT-command: %s \n\n", cmd.c_str());
  cmd.append("\r\n");
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  m_TimeoutTimer.StartTimeMeassurement();
  /*eResponse response = */WaitForResponse();
  Tools::Wait::WaitMs(waitMsAfterSending);
}

void ESP8266::SendCommandWithoutWaiting(std::string cmd){
  trace_printf("Sending AT-command without waiting: %s \n\n", cmd.c_str());
  cmd.append("\r\n");
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
}

void ESP8266::SendGetRequest(std::string cmd){
  trace_printf("Sending GET request: %s \n\n", cmd.c_str());
  cmd.append("\n");
  
  char aBuffer[4];
  itoa(cmd.length() + 1, aBuffer, 10);
  
  std::string s = "AT+CIPSEND=";
  s.append(aBuffer);
  s.append("\r\n");
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(s.c_str())), s.length());
  Tools::Wait::WaitMs(2000);
  
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitMs(2000);
  
  s = "\n";
  SysTick->CTRL  = 0;
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(s.c_str())), s.length());
//  NVIC_EnableIRQ(SysTick_IRQn);
}

void ESP8266::ExitTransmissionMode(void){
  std::string cmd = "+++\r";
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitMs(100);
  
  cmd = "\r\n";
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitMs(100);
  
  cmd = "+++";
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitMs(100);
  
  cmd = "\r";
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitMs(100);
  
  cmd = "\r\n\r\n";
  HW_USART::Transmit(reinterpret_cast<uint8_t*>(const_cast<char*>(cmd.c_str())), cmd.length());
  Tools::Wait::WaitMs(100);
}
  

ESP8266::eResponse ESP8266::WaitForResponse(void){
  while ((m_TimeoutTimer.GetTimeDiffMilliSec() < TIMEOUT) && (m_eResponse == NOT_RESPONDING));
  
  if (m_eResponse == NOT_RESPONDING){
    trace_printf("ESP8266 not responding\n\n");
  }
  
  return m_eResponse;
}

}
