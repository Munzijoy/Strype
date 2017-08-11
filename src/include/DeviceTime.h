/*
 * DeviceTime.h
 *
 *  Created on: 09.11.2016
 *      Author: t.linz
 */

#ifndef DEVICETIME_H_
#define DEVICETIME_H_

#include <time.h>
#include <string>
#include <stdio.h>

#include "Develop.h"
#include "diag/Trace.h"

namespace Application {

class DeviceTime {
private :
  static struct tm* gTimeStruct;
#if DEBUG_DEVICE_TIME
  static bool bMinuteHasPassed;
#endif
  
public:
  
  inline static std::string GetDeviceDateAndTimeString(void){
    return GetPrettyDeviceTime("%A %d.%m.%Y %X");
  }
  
  // refer to http://www.cplusplus.com/reference/ctime/strftime/
  inline static std::string GetStrftimeString(const char* pFormat){
    return GetPrettyDeviceTime(pFormat);
  }
  
  inline static std::string GetDeviceTimeString(void){
    return GetPrettyDeviceTime("%X");
  };
  
  inline static void DebugDeviceTime(void){
      UpdateDeviceTime();
#if DEBUG_DEVICE_TIME
    if (bMinuteHasPassed){
        bMinuteHasPassed = false;
        trace_printf(std::string(GetDeviceTimeString() + "\n").c_str());
    }
#endif
  }
   
  inline static void UpdateDeviceTime(void){
      time_t deviceTime = (time_t)RTC_GetCounter();
      gTimeStruct = localtime(&deviceTime);
#if DEBUG_DEVICE_TIME
  bMinuteHasPassed = (!(deviceTime%60));
#endif
  }
  
private:
  inline static std::string GetPrettyDeviceTime(const char* pFormat){
    std::string result;
    char buffer[32];
    strftime(buffer, 32, pFormat, gTimeStruct);
    result = buffer;

    return result;
  };
};

}

#endif /* DEVICETIME_H_ */
