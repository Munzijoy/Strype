#include "HW_RCC.h"
#include "HW_SPI.h"
#include "HW_RTC.h"
#include "HW_USART.h"

#include "diag/Trace.h"
#include "ReadSemihosting.h"

#include "LedWrapper.h"
#include "MAX7219.h"
#include "DeviceTime.h"
#include "UserSettings.h"
#include "MyESP8266.h"
#include "Wait.h"

#include "Develop.h"

#include <stdlib.h>
#include <signal.h>

#include "FreeRTOS.h"
#include "task.h"

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma GCC diagnostic ignored "-Wnarrowing"

struct tm* Application::DeviceTime::gTimeStruct(NULL);
#if DEBUG_DEVICE_TIME
bool Application::DeviceTime::bMinuteHasPassed = true;
#endif

extern "C" void _exit(int code){
#if !defined(DEBUG)
  __reset_hardware();
#endif
  trace_printf("%s!!!!! Cat ass trophy number %d!!!!", __PRETTY_FUNCTION__, code);
  Application::LedWrapper::DisplayString(__PRETTY_FUNCTION__);
  Application::LedWrapper::DisplayString("Cat ass trophy");
  for(;;){}
}

int
main(int /*argc*/, char* /*argv[]*/){
    trace_printf((char*)REBOOT_STRING,__PRETTY_FUNCTION__);
    
    Application::DeviceTime::UpdateDeviceTime();
    
    Hardware::HW_RCC::Init();
    Hardware::HW_RTC::Init();
    Hardware::HW_SPI::Init();
    Hardware::HW_USART::Init();
   
    Application::LedWrapper::InitLedWrapper();
    Application::UserSettings::Init();
    
    Application::LedWrapper::DisplayString(Application::DeviceTime::GetDeviceDateAndTimeString(), 20);
    
    trace_printf("Entering main loop\n");
    
    
    while (1){
        vTaskStartScheduler();
    }
}

extern "C"{
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	/* This function will get called if a task overflows its stack.   If the
	parameters are corrupt then inspect pxCurrentTCB to find which was the
	offending task. */

	( void ) pxTask;
	( void ) pcTaskName;

	for( ;; );
}
/*-----------------------------------------------------------*/

void assert_failed( unsigned char *pucFile, unsigned long ulLine )
{
	( void ) pucFile;
	( void ) ulLine;

	for( ;; );
}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
