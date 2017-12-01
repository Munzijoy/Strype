/*
 * OpenWeatherMap.cpp
 *
 *  Created on: 27.11.2017
 *      Author: t.linz
 */

#include "OpenWeatherMap.h"
#include "WiFi.h"

namespace Application {
namespace API {

using namespace rapidjson;
const OnlineApiBase::ApiAddress OpenWeatherMap::_apiAddress = {
  "api.openweathermap.org", 
  "/data/2.5/weather?lat=51.390127&lon=12.334344&APPID=cac07d5e5deaaea2640bff05a34076ad&units=metric"
};

void OpenWeatherMap::ReceiveData(void){  
  try {
    GetJsonData();
    OpenWeatherMapJsonData resultData;
    
    resultData._coord_lon = _document["coord"]["lon"].GetFloat();
    resultData._coord_lat = _document["coord"]["lat"].GetFloat();
    resultData._weather_0_id = _document["weather"][0]["id"].GetInt();
    resultData._weather_0_main = _document["weather"][0]["main"].GetString();
    resultData._weather_0_description = _document["weather"][0]["description"].GetString();
    resultData._weather_0_icon = _document["weather"][0]["icon"].GetString();
    resultData._base = _document["base"].GetString();
    resultData._main_temp = _document["main"]["temp"].GetFloat();
    resultData._main_pressure = _document["main"]["pressure"].GetInt();
    resultData._main_humidity = _document["main"]["humidity"].GetInt();
    resultData._main_tempmin = _document["main"]["temp_min"].GetFloat();
    resultData._main_tempmax = _document["main"]["temp_max"].GetFloat();
    resultData._visibility = _document["visibility"].GetInt();
    resultData._wind_speed = _document["wind"]["speed"].GetFloat();
    resultData._wind_degree = _document["wind"]["deg"].GetInt();
    resultData._clouds_all = _document["clouds"]["all"].GetInt();
    resultData._dt = _document["dt"].GetInt();
    resultData._sys_type = _document["sys"]["type"].GetInt();
    resultData._sys_id = _document["sys"]["id"].GetInt();
    resultData._sys_message = _document["sys"]["message"].GetFloat();
    resultData._sys_country = _document["sys"]["country"].GetString();
    resultData._sys_sunrise = _document["sys"]["sunrise"].GetInt();
    resultData._sys_sunset = _document["sys"]["sunset"].GetInt();
    resultData._id = _document["id"].GetInt();
    resultData._name = _document["name"].GetString();
    resultData._cod = _document["cod"].GetInt();
  
    _jsonData = resultData;
  } catch (WiFiException& e){
  }
}

}
}

