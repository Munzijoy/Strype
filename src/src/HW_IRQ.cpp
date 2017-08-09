/*
 * HW_RTC.cpp
 *
 *  Created on: 08.11.2016
 *      Author: t.linz
 */
#include "stm32f10x_rtc.h"
#include "core_cm3.h"
#include "HW_RTC.h"
#include "DeviceTime.h"
#include "Delay.h"
#include "diag/Trace.h"
#include "Develop.h"

// ISRs needs to be written in a C section, not C++, thatswhy this is a C file,
// so no seperate sections are needed. Place all required ISRs here (names can
// be found in the asm startup file (*.s)

// Real Time Clock Interrupt handler, catching the secound interrupt only
volatile int32_t gs32SysTickCnt=0;

extern "C" void RTC_IRQHandler(void){
    trace_puts("RTC Interrupt\n");
        // only catch the second interrupt
    if (RTC_GetITStatus(RTC_IT_SEC) != RESET){
        
        // refer to en.CD00207941.pdf
        uint32_t u32RtcCounter = RTC_GetCounter();
        gTimeStruct.tm_hour =  u32RtcCounter / 3600;
        gTimeStruct.tm_min = (u32RtcCounter % 3600) / 60;
        gTimeStruct.tm_sec = (u32RtcCounter % 3600) % 60;
        
        // Clear the RTC Second interrupt
        RTC_ClearITPendingBit(RTC_IT_SEC);
        // Wait until last write operation on RTC registers has finished
        RTC_WaitForLastTask();
        trace_printf("RTC Interrupt %d: %d:%d:%d", u32RtcCounter, gTimeStruct.tm_hour, gTimeStruct.tm_min, gTimeStruct.tm_sec);
    }
}

// ISR is called every microsecond
extern "C" void SysTick_Handler(void){
  Tools::Timing::gvs32SysTickCnt++;
  volatile uint32_t localSysTick = Tools::Timing::gvs32SysTickCnt; 

#if (DEBUG_SYSTICK_EVERY_X_SECONDS != 0)
  if (!(localSysTick % (DEBUG_SYSTICK_EVERY_X_SECONDS * 1000))){ // alle 1 Sekunden
    trace_printf("SysTick Interrupt %d\n", localSysTick);
  }
#endif
}
