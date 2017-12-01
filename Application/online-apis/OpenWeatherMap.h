/*
 * OpenWeatherMap.h
 *
 *  Created on: 27.11.2017
 *      Author: t.linz
 */

#ifndef APPLICATION_ONLINE_APIS_OPENWEATHERMAP_H_
#define APPLICATION_ONLINE_APIS_OPENWEATHERMAP_H_

#include <time.h>
#include "OnlineApiBase.h"

namespace Application {
namespace API {

class OpenWeatherMap : public OnlineApiBase {
public:
  OpenWeatherMap(void) : OpenWeatherMap(_apiAddress){}
  OpenWeatherMap(ApiAddress apiAddress) : OnlineApiBase(apiAddress){}
  
  struct OpenWeatherMapJsonData {
    float _coord_lon;
    float _coord_lat;
    int _weather_0_id;
    const char* _weather_0_main;
    const char* _weather_0_description;
    const char* _weather_0_icon;
    const char* _base;
    float _main_temp;
    int _main_pressure;
    int _main_humidity;
    float _main_tempmin;
    float _main_tempmax;
    int _visibility;
    float _wind_speed;
    int _wind_degree;
    int _clouds_all;
    time_t _dt;
    int _sys_type;
    int _sys_id;
    float _sys_message;
    const char* _sys_country;
    time_t _sys_sunrise;
    time_t _sys_sunset;
    int _id;
    const char* _name;
    int _cod;
  };
  
private:
  OpenWeatherMapJsonData _jsonData;
  
public:
  OpenWeatherMapJsonData GetJsonResultData(void){ return _jsonData; }
  void ReceiveData(void);
  void ConvertData(void){}

private:
  static const char* _startString;
  static const ApiAddress _apiAddress;
};

}
}

#endif /* APPLICATION_ONLINE_APIS_OPENWEATHERMAP_H_ */
