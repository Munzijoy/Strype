/*
 * ConvertUnixTimeApi.h
 *
 *  Created on: 29.11.2017
 *      Author: t.linz
 */

#ifndef APPLICATION_ONLINE_APIS_CONVERTUNIXTIMEAPI_H_
#define APPLICATION_ONLINE_APIS_CONVERTUNIXTIMEAPI_H_


#include <time.h>
#include "OnlineApiBase.h"

namespace Application {
namespace API {

class ConvertUnixTimeApi : public OnlineApiBase {
public:
  ConvertUnixTimeApi(void) : ConvertUnixTimeApi(_apiAddress){}
  ConvertUnixTimeApi(ApiAddress apiAddress) : OnlineApiBase(apiAddress){}
  
  struct ConvertUnixTimeApiJsonData {
    const char*_localDate;
    const char*_utcDate;
    const char*_format;
    const char* _returnType;
    time_t _timestamp;
    const char* _timezone;
    bool _daylightSavingTime;
    const char* _url;
  };
  
private:
  ConvertUnixTimeApiJsonData _jsonData;
  
public:
  ConvertUnixTimeApiJsonData GetJsonResultData(void){ return _jsonData; }
  void ReceiveData(void);
  void ConvertData(void){}

private:
  static const char* _startString;
  static const ApiAddress _apiAddress;
};

}
}

#endif /* APPLICATION_ONLINE_APIS_CONVERTUNIXTIMEAPI_H_ */

