#include <stdio.h>
#include <stdlib.h>
#include "HW_RCC.h"
#include "HW_SPI.h"
#include "HW_RTC.h"
#include "Delay.h"
#include "diag/Trace.h"
#include "LedWrapper.h"
#include "MAX7219.h"

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main(int argc, char* argv[])
{
  trace_printf("Reboot -> %s\n", __PRETTY_FUNCTION__);
  Hardware::HW_RCC::Init();
  
  RCC_ClocksTypeDef Clocks;
  RCC_GetClocksFreq(&Clocks);
  SysTick_Config(Clocks.HCLK_Frequency / 1000 - 1 );  // 1000 Hz ( T=1ms)
  
  Hardware::HW_RTC::Init();
  Hardware::HW_SPI::Init();
 
  Application::LedWrapper::InitLedWrapper();
  
  trace_printf("Entering main loop\n");
  while (1){
    Application::LedWrapper::DisplayString("Strype by Tom Linz", 500);
  }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
