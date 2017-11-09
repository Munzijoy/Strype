/*
 * HW_RTC.cpp
 *
 *  Created on: 08.11.2016
 *      Author: t.linz
 */
#include "Wait.h"
#include "stm32f10x_rtc.h"
#include "core_cm3.h"
#include "HW_RTC.h"
#include "DeviceTime.h"
#include "diag/Trace.h"
#include "Develop.h"
#include <cstring>
#include <bits/stl_algo.h>
#include <MyESP8266.h>

extern "C" void RTC_IRQHandler(void){
    // only catch the second interrupt
    if (RTC_GetITStatus(RTC_IT_SEC) != RESET){
        Application::DeviceTime::UpdateDeviceTime();
        
        RTC_ClearITPendingBit(RTC_IT_SEC); // Clear the RTC Second interrupt
        RTC_WaitForLastTask();
    }
}

// ISR is called every microsecond
extern "C" void SysTick_Handler(void){
  Tools::Wait::gvu32SysTickCnt++;
#if (DEBUG_SYSTICK_EVERY_X_SECONDS != 0)
  volatile uint32_t localSysTick = Tools::Timing::gvu32SysTickCnt; 
  if (!(localSysTick % (DEBUG_SYSTICK_EVERY_X_SECONDS * 1000))){ // alle 1 Sekunden
    trace_printf("SysTick Interrupt %d\n", localSysTick);
  }
#endif
}

extern "C" void USART1_IRQHandler(void){
  if (USART_GetFlagStatus(USART1, USART_SR_RXNE) != RESET){
    (const_cast<std::string&>(Hardware::ESP8266::m_UsartRxString)) += (static_cast<char>(USART_ReceiveData(USART1)));
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
  }
}
