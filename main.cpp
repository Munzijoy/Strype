#include "mbed.h"
#include "LedWrapper.h"
#include "WiFi.h"
#include "SystemTime.h"

#define DEBUG_TIME_ON_DISPLAY 1
void SystemTimeThread(void);

// main() runs in its own thread in the OS
int main(void) _Noreturn {
  Application::LedWrapper::InitLedWrapper();

  Thread systemTimeThread(osPriorityNormal, 32 * 1024);
  systemTimeThread.start(&SystemTimeThread);
 
  while(1);
}

void SystemTimeThread(void) _Noreturn {
    Application::SystemTime::SetTimeZone("CET-1CEST-2");
    
    try {
      Application::SystemTime::InitSystemTimeOnline();
    } catch (Application::WiFiException& e){
      HAL_NVIC_SystemReset(); // if system time could not be initialized, reboot is required and exception is thrown
    }
    
    // after init: call online time api once every hour
    Ticker hourTicker;
    hourTicker.attach(Application::SystemTime::InitSystemTimeOnline, 3600);
  
      while(1){
#if DEBUG_TIME_ON_DISPLAY
        Application::LedWrapper::DisplayStringSimple(Application::SystemTime::GetSystemTimeString());
#endif
      }
}
