/*
 * OnlineApiBase.cpp
 *
 *  Created on: 27.11.2017
 *      Author: t.linz
 */

#include "OnlineApiBase.h"
#include "WiFi.h"
#include "LedWrapper.h"
#include <string.h>
#include <sstream>

namespace Application {
namespace API {

void OnlineApiBase::GetJsonData(const char* startString){
  if (!Application::WiFi::_WiFiInstance.IsConnected()){
    try {
      Application::WiFi::_WiFiInstance.Connect();
    } catch (WiFiException& e){
    }
  }
  
  Application::LedWrapper::DisplayString("wait");
  
  string resultString;
  
  try {
    resultString = Application::WiFi::_WiFiInstance.SendGetRequest(_apiAddress._url, _apiAddress._path);
  } catch (WiFiException& e){
    return;
  }
    
    if (!resultString.empty() && (resultString.find("404 Not Found") == std::string::npos)){
      size_t jsonStartPos = resultString.find(startString);
      if (jsonStartPos != string::npos){
        string jsonResultString = resultString.substr(jsonStartPos + 4); 
        if (!jsonResultString.empty()){
          _document.Parse(jsonResultString.c_str());
          if (!_document.HasParseError()){
            return;
          }
        }
      }
    }
  
  throw WiFiException("JSON Data not valid");
}

}
}
