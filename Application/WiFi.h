/*
 * WiFi.h
 *
 *  Created on: 17.11.2017
 *      Author: t.linz
 */

#ifndef WIFI_H_
#define WIFI_H_

#include <string>
#include "ESP8266Interface.h"
#include "LedWrapper.h"

#ifndef MBED_CFG_ESP8266_TX
#define MBED_CFG_ESP8266_TX SERIAL_TX
#endif

#ifndef MBED_CFG_ESP8266_RX
#define MBED_CFG_ESP8266_RX SERIAL_RX
#endif

namespace Application {

class WiFiException : public DisplayException {
public:
  WiFiException(const char* exceptionString) : DisplayException(exceptionString){}
};

class WiFi {
public:
  std::string SendGetRequest(std::string url, std::string path);
  int Connect(void);
  static WiFi _WiFiInstance;
  bool IsConnected(void){ return _isConnected; }
private:
  WiFi(const char* ssid, const char* pass, nsapi_security_t securityType);
  WiFi(void) = delete;
  const char* _ssid;
  const char* _pass;
  nsapi_security_t _securityType;
  ESP8266Interface _networkInterface;
  bool _isConnected;
};

}

#endif /* WIFI_H_ */
