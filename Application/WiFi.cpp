/*
 * WiFi.cpp
 *
 *  Created on: 17.11.2017
 *      Author: t.linz
 */

#include "WiFi.h"
#include <sstream>

namespace Application {

WiFi WiFi::_WiFiInstance("ES_8102", "skilager", NSAPI_SECURITY_WPA2);

WiFi::WiFi(const char* ssid, const char* pass, nsapi_security_t securityType) :
    _ssid(ssid),
    _pass(pass),
    _securityType(securityType),
    _networkInterface(PB_10, PB_11, false),
    _isConnected(false)
{
}

int WiFi::Connect(void){
//  char connectString[30];
//  sprintf(connectString, "Connecting to %s...", _ssid);
//  Application::LedWrapper::DisplayString(connectString);
        
  int result = _networkInterface.connect(_ssid, _pass, _securityType);
  
  switch (result){
    case (NSAPI_ERROR_UNSUPPORTED):
        throw WiFiException("Invalid channel");
        while(1);
    break;
    
    case (NSAPI_ERROR_DEVICE_ERROR):
        throw WiFiException("WiFi device error");
        while(1);
    break;
    
    case (NSAPI_ERROR_DHCP_FAILURE):
        throw WiFiException("DHCP Error");
        while(1);
    break;
    
    case (NSAPI_ERROR_NO_CONNECTION):{
        char resultString[30];
        sprintf(resultString, "No Connection to WiFi network %s. Check credentials.", _ssid);
        throw WiFiException(resultString);
    
    break;
    }
    
    case (NSAPI_ERROR_OK):{
//        Application::LedWrapper::DisplayString("connect OK");
    break;
    }
    
    default:
      throw WiFiException("Unknown error during connection");
  }
  
  return result;
}

std::string WiFi::SendGetRequest(std::string url, std::string path){
    const int RECV_BUFFER_SIZE = 2000;  
    char receiveBuffer[RECV_BUFFER_SIZE] = {0};
    TCPSocket tcpSocket(&_networkInterface);
    
    if (tcpSocket.connect(url.c_str(), 80) == 0) {
      std::stringstream httpGetStringStream;
      std::stringstream httpReceiveStream;
      httpGetStringStream << "GET " << path.c_str() << " HTTP/1.1\nHost: " << url.c_str() << "\n\n";
      std::string httpGetString = httpGetStringStream.str();
      
      // Send GET command
      tcpSocket.send(httpGetString.c_str(), httpGetString.length());

      // Server will respond with HTTP GET's success code
      const int ret = tcpSocket.recv(receiveBuffer, sizeof(receiveBuffer) - 1);
      receiveBuffer[ret] = '\0';
      
      tcpSocket.close();
      _networkInterface.disconnect();
      
      if (ret <= 0){
        throw WiFiException("GET returned nothing");
      }
      
      return std::string(receiveBuffer);
    } else {
      throw WiFiException("TCP socket not connected");
    }
}

}

