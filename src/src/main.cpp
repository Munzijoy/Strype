#include "Wait.h"
#include "ReadSemihosting.h"
#include "HW_RCC.h"
#include "HW_SPI.h"
#include "HW_RTC.h"
#include "HW_USART.h"
#include "diag/Trace.h"
#include "LedWrapper.h"
#include "MAX7219.h"
#include "DeviceTime.h"
#include "ESP8266.h"
#include "UserSettings.h"

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

#if DEVELOP
//    Application::UserSettings::TestUserSettings();
//    Application::UserSettings::Init();
#endif
    
    trace_printf("Entering main loop\n");
    
//    Hardware::ESP8266::ExitTransmissionMode();
//    Hardware::ESP8266::SendCommand("AT+RST"); // reset
//    Hardware::ESP8266::SendCommand("AT"); // test command
//    Hardware::ESP8266::SendCommand("AT+CWMODE=1"); // client mode (not access point mode)
//    Hardware::ESP8266::SendCommand("AT+CIPMUX=0"); // single connection mode
////        Hardware::ESP8266::SendCommand("AT+RST"); // reset device
////        Hardware::ESP8266::SendCommand("AT+CWLAP"); //list available access points
////        Hardware::ESP8266::SendCommand("AT+CWJAP=\"ES_8102\",\"skilager\"");
//    Hardware::ESP8266::SendCommand("AT+CIPMODE=0"); // unvarnished transmission mode
//    Hardware::ESP8266::SendCommand("AT+CIPCLOSE");
//    Hardware::ESP8266::SendCommand("AT+CIPSTART=\"TCP\",\"api.openweathermap.org\",80", 2000); // create TCP connection
//    Hardware::ESP8266::SendGetRequest("GET /data/2.5/weather?lat=51.390127&lon=12.334344&APPID=cac07d5e5deaaea2640bff05a34076ad HTTP/1.0");
//    trace_printf("Exiting Transmission mode...\n");
////    Hardware::ESP8266::ExitTransmissionMode();
//    Hardware::ESP8266::SendCommand("AT"); // test command
    
    while (1){
	vTaskStartScheduler();
// ===================================================================
//        std::string myString = ReadString();
//        if (myString.length() > 0){
//              Application::LedWrapper::DisplayString(myString, 20);
//        }
// ===================================================================      
//        Application::LedWrapper::DisplayString(Application::DeviceTime::GetDeviceDateAndTimeString(), 20);
        
// ===================================================================

    }
}


#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
