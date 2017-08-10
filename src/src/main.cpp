#include <stdio.h>
#include <stdlib.h>
#include "HW_RCC.h"
#include "HW_SPI.h"
#include "HW_RTC.h"
#include "Delay.h"
#include "diag/Trace.h"
#include "LedWrapper.h"
#include "MAX7219.h"
#include "DeviceTime.h"
#include <time.h>

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wunused-parameter"

struct tm* Application::DeviceTime::gTimeStruct(NULL);
#if PRINT_DEVICE_TIME
bool Application::DeviceTime::bMinuteHasPassed = true;
#endif

int
main(int /*argc*/, char* /*argv[]*/){
    trace_printf("Reboot!!! Starting at %s\n",__PRETTY_FUNCTION__);
    
    // set time zone (does not work yet)
    putenv((char*)"TZ=CST6CDT");
    tzset();
    
    Application::DeviceTime::UpdateAndPrintDeviceTime();
    
    Hardware::HW_RCC::Init();
    Hardware::HW_RTC::Init();
    Hardware::HW_SPI::Init();
   
    Application::LedWrapper::InitLedWrapper();
    
    trace_printf("Entering main loop\n");
    while (1){
        Application::LedWrapper::DisplayString(Application::DeviceTime::GetDeviceTimeString(), 50);
    }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
