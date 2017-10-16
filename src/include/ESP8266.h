/*
 * ESP8266.h
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#ifndef HARDWARE_ESP8266_H_
#define HARDWARE_ESP8266_H_

#include <string>
#include "Wait.h"

namespace Hardware {
class ESP8266 {
public:
  enum eResponse {
    OK,
    ERROR,
    NOT_RESPONDING,
  };
  static const uint16_t TIMEOUT = 5000; // timeout in ms
  
  static void SendCommand(std::string cmd, uint32_t waitMsAfterSending = 500);
  static void SendCommandWithoutWaiting(std::string cmd);
  static void SendGetRequest(std::string cmd);
  static void ExitTransmissionMode(void);
  static void SetSuccessFlag(eResponse response){ m_eResponse = response; };
  static eResponse WaitForResponse(void);
  static volatile std::string m_UsartRxString;
private:
  static eResponse m_eResponse;
  static Tools::Wait m_TimeoutTimer;
};
}


#endif /* HARDWARE_ESP8266_H_ */
