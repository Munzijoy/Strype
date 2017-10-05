/*
 * ESP8266.h
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#ifndef HARDWARE_ESP8266_H_
#define HARDWARE_ESP8266_H_

#include <string>

namespace Hardware {
class ESP8266 {
public:
  static void SendCommand(std::string cmd);
  static void Test(void);
};
}



#endif /* HARDWARE_ESP8266_H_ */
