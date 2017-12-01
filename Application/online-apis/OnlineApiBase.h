/*
 * OnlineApiBase.h
 *
 *  Created on: 27.11.2017
 *      Author: t.linz
 */

#ifndef APPLICATION_ONLINE_APIS_ONLINEAPIBASE_H_
#define APPLICATION_ONLINE_APIS_ONLINEAPIBASE_H_

#include "rapidjson/document.h"
#include "OnlineApiBase.h"
#include "rapidjson/document.h"
#include "WiFi.h"

namespace Application {
namespace API {

class OnlineApiBase {
protected:
  struct ApiAddress {
    const char* _url;
    const char* _path;
  };

  OnlineApiBase(ApiAddress apiAddress) : _apiAddress(apiAddress), _dataReceived(false){}
  void GetJsonData(const char* startString = "\r\n\r\n");
  
  ApiAddress _apiAddress;
  bool _dataReceived;
  rapidjson::Document _document;
};

}
}

#endif /* APPLICATION_ONLINE_APIS_ONLINEAPIBASE_H_ */
