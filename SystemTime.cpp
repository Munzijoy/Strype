/*
 * SystemTime.cpp
 *
 *  Created on: 04.01.2018
 *      Author: t.linz
 */

#include "SystemTime.h"

#include "mbed.h"
#include "LedWrapper.h"
#include "ConvertUnixTimeApi.h"

#include <iostream>
#include <time.h>
#include <sstream>

namespace Application {

std::string SystemTime::GetSystemTimeString(void){
  char aTimeBufferH[3];
  char aTimeBufferM[3];

  time_t sysTimeStamp = time(NULL);

  tm result;
  localtime_r(&sysTimeStamp, &result);

//  struct tm* time = localtime(&sysTimeStamp);
  strftime(aTimeBufferH, sizeof(aTimeBufferH), "%H", &result);
  strftime(aTimeBufferM, sizeof(aTimeBufferM), "%M", &result);
  std::stringstream s;
  s << aTimeBufferH << (!(sysTimeStamp % 2) ? ":" : " ") << aTimeBufferM;
  
  return s.str();
}

void SystemTime::InitSystemTimeOnline(void){
  try {
    Application::API::ConvertUnixTimeApi convertunixtimeapi;
    convertunixtimeapi.ReceiveData();
    Application::API::ConvertUnixTimeApi::ConvertUnixTimeApiJsonData result = convertunixtimeapi.GetJsonResultData();
    set_time(result._timestamp);
  } catch (Application::WiFiException& e){
    // timestamp could not be received from API
  }
}

void SystemTime::SetTimeZone(std::string timeZoneString){
    setenv("TZ", timeZoneString.c_str(), 1);
    tzset();
}

}
