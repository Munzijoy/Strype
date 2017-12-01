/*
 * ConvertUnixTimeApi.cpp
 *
 *  Created on: 29.11.2017
 *      Author: t.linz
 */

#include "ConvertUnixTimeApi.h"

namespace Application {
namespace API {

const OnlineApiBase::ApiAddress ConvertUnixTimeApi::_apiAddress = {
  "convert-unix-time.com", 
  "/api?timestamp=now"
};

void ConvertUnixTimeApi::ReceiveData(void){  
  try {
    GetJsonData();
    ConvertUnixTimeApiJsonData resultData;
    
    resultData._localDate = _document["localDate"].GetString();
    resultData._utcDate = _document["utcDate"].GetString();;
    resultData._format = _document["format"].GetString();;
    resultData._returnType = _document["returnType"].GetString();;
    resultData._timestamp = _document["timestamp"].GetInt();
    resultData._timezone = _document["timezone"].GetString();;
    resultData._daylightSavingTime = _document["daylightSavingTime"].GetBool();
    resultData._url = _document["url"].GetString();;
  
    _jsonData = resultData;
  } catch (WiFiException& e){
  }
}

}
}
