/*
 * HW_RTC.cpp
 *
 *  Created on: 08.11.2016
 *      Author: t.linz
 */

#include "HW_RTC.h"
//#include "stm32f10x_nvic.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_bkp.h"
#include "stm32f10x_rtc.h"
#include "DeviceTime.h"
#include "misc.h"

namespace Hardware {


void HW_RTC::Init(void){
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP | RCC_APB1Periph_PWR, ENABLE);
  PWR_BackupAccessCmd(ENABLE);
//  RCC_BackupResetCmd(DISABLE);
  
  RTC_WaitForLastTask();
  RTC_ClearFlag(RTC_FLAG_RSF);
  
  RTC_WaitForLastTask();
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
  
  RTC_WaitForLastTask();
  RCC_LSEConfig(ENABLE);
  
  RTC_WaitForLastTask();
  RCC_RTCCLKCmd(ENABLE);

  RTC_WaitForLastTask();
  RTC_SetPrescaler(32768);  // RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1)
  
  RTC_WaitForLastTask();
  RTC_ITConfig(RTC_IT_SEC, ENABLE);

  // warte bis synconisiert
  RTC_WaitForSynchro();
  

}

}

