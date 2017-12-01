#include "mbed.h"
#include "LedWrapper.h"
#include "ConvertUnixTimeApi.h"

#include <time.h>
#include <sstream>

using namespace rapidjson;

void test_thread(void);
void InitSystemTimeOnline(void);
std::string GetSystemTimeString(void);

// main() runs in its own thread in the OS
int main(void) _Noreturn {
  Application::LedWrapper::InitLedWrapper();
  
  Thread t(osPriorityNormal, 32 * 1024);
  t.start(&test_thread);
 
  while(1);
}

void test_thread(void) _Noreturn {
  try {
    InitSystemTimeOnline();
  
    while(1){
      Application::LedWrapper::DisplayString(GetSystemTimeString());
    }
    
  } catch (Application::WiFiException& e){
    while(1);
  }
}

std::string GetSystemTimeString(void){
  char aTimeBuffer[20];
  time_t sysTimeStamp = time(NULL);
  struct tm* time = localtime(&sysTimeStamp);
  strftime(aTimeBuffer, sizeof(aTimeBuffer), "%M", time);
  std::stringstream s;
  s << (!(sysTimeStamp % 2) ? ":" : " ") << aTimeBuffer;
  
  return s.str();
}

void InitSystemTimeOnline(void){
  try {
    Application::API::ConvertUnixTimeApi convertunixtimeapi;
    convertunixtimeapi.ReceiveData();
    Application::API::ConvertUnixTimeApi::ConvertUnixTimeApiJsonData result = convertunixtimeapi.GetJsonResultData();
    set_time(result._timestamp);
  } catch (Application::WiFiException& e){
  }
}



