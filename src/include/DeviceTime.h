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
#if PRINT_DEVICE_TIME
  static bool bMinuteHasPassed;
#endif
  
public:
  inline static std::string GetDeviceTimeString(void){
    std::string result;
#if GERMAN_DATE_FORMAT
    char buffer[32];
    const char* format = "%d.%m.%Y - %X";
    strftime(buffer, 80, format, gTimeStruct);
    result = buffer;
#elif STD_DATE_FORMAT
    result = asctime(gTimeStruct);
#endif
    return result;
  };
  
  inline static void UpdateAndPrintDeviceTime(void){
      UpdateDeviceTime();
#if PRINT_DEVICE_TIME
    if (bMinuteHasPassed){
        bMinuteHasPassed = false;
        trace_printf(GetDeviceTimeString().c_str());
    }
#endif
  }
    
  inline static void UpdateDeviceTime(void){
      time_t deviceTime = (time_t)RTC_GetCounter();
      gTimeStruct = gmtime(&deviceTime);
#if PRINT_DEVICE_TIME
  bMinuteHasPassed = (!(deviceTime%60));
#endif
  }
};

}

#endif /* DEVICETIME_H_ */
