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
    while (1){
// ===================================================================
//        std::string myString = ReadString();
//        if (myString.length() > 0){
//              Application::LedWrapper::DisplayString(myString, 20);
//        }
// ===================================================================      
//        Application::LedWrapper::DisplayString(Application::DeviceTime::GetDeviceDateAndTimeString(), 20);
        Hardware::ESP8266::Test();
// ===================================================================

    }
}


#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
