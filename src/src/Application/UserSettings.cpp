/*
 * UserSettings.cpp
 *
 *  Created on: 16.08.2017
 *      Author: t.linz
 */

#include "UserSettings.h"
#include "diag/Trace.h"

namespace Application {

UserSettings::MainMenuQueueType UserSettings::_mainMenu;
UserSettings::SubMenuQueueType UserSettings::_subMenuA;
UserSettings::SubMenuQueueType UserSettings::_subMenuB;
UserSettings::MainMenuQueueType::iterator UserSettings::_mainMenuIter;
UserSettings::SubMenuQueueType::iterator UserSettings::_subMenuIter;
UserSettings::SubMenuQueueType::iterator UserSettings::_subMenuEnd;
UserSettings::MainMenuQueueType::iterator UserSettings::_mainMenuEnd;
UserSettings::SubMenuContent UserSettings::_actSubMenuContent;
std::string UserSettings::_actMainMenuParrentString;

std::string UserSettings::GetNextSubMenuString(void){
    if (_subMenuIter != _subMenuEnd){
      _subMenuIter++;
      _actSubMenuContent = (*_subMenuIter);
    }
    
    trace_printf("%s liefert %s\n", __PRETTY_FUNCTION__,  _actSubMenuContent._subMenuString.c_str());
    return _actSubMenuContent._subMenuString;
}

std::string UserSettings::GetCurrentSubMenuString(void){
    trace_printf("%s liefert %s\n",  __PRETTY_FUNCTION__, _actSubMenuContent._subMenuString.c_str());
    return _actSubMenuContent._subMenuString;
}

std::string UserSettings::GetCurrentMainMenuString(void){
    trace_printf("%s liefert %s\n", __PRETTY_FUNCTION__,  _actMainMenuParrentString.c_str());
    return _actMainMenuParrentString;
}

std::string UserSettings::GetNextMainMenuString(void){
      _subMenuEnd = (*_mainMenuIter).end() - 1;
  
      if (_mainMenuIter != _mainMenuEnd) {
        ++_mainMenuIter;
        _subMenuIter = (*_mainMenuIter).begin();
        _actSubMenuContent = *_subMenuIter;
        _actMainMenuParrentString = _actSubMenuContent._mainMenuParrentString.c_str();
      }
  
    trace_printf("%s liefert %s\n",  __PRETTY_FUNCTION__, _actMainMenuParrentString.c_str());
    return _actMainMenuParrentString;
}

void UserSettings::CallSubMenuFunction(void){
  _actSubMenuContent._callbackFunc();
}

#if DEVELOP
void UserSettings::TestUserSettings(void){
    // forwards
    for (uint8_t j = 0; j < 4; j++) {
      for (uint8_t i = 0; i < 7; i++) {
        _actSubMenuContent = (*_subMenuIter);
        trace_printf("SubMenu %s vom Hauptmenu %s mit Callback %d\n", 
                     _actSubMenuContent._subMenuString.c_str(), 
                     _actSubMenuContent._mainMenuParrentString.c_str(),
                     _actSubMenuContent._callbackFunc);

        if (_subMenuIter != _subMenuEnd){
          _subMenuIter++;
          _actSubMenuContent = (*_subMenuIter);
        }
      }
      
      if (_mainMenuIter != _mainMenuEnd) {
        ++_mainMenuIter;
        _actMainMenuParrentString = _actSubMenuContent._mainMenuParrentString;
      }
    }

    // backwards
    for (uint8_t j = 0; j < 4; j++) {
      for (uint8_t i = 0; i < 7; i++) {
      }
    }
}
#endif

void UserSettings::Init(void){
SubMenuContent menu[10];

    menu[0]._subMenuString = "A1";
    menu[0]._mainMenuParrentString = "A";
    menu[0]._callbackFunc = A1Callback;
    _subMenuA.push_back(menu[0]);

    menu[1]._subMenuString = "A2";
    menu[1]._mainMenuParrentString = "A";
    menu[1]._callbackFunc = A2Callback;
    _subMenuA.push_back(menu[1]);

    menu[2]._subMenuString = "A3";
    menu[2]._mainMenuParrentString = "A";
    menu[2]._callbackFunc = A3Callback;
    _subMenuA.push_back(menu[2]);

    menu[3]._subMenuString = "B1";
    menu[3]._mainMenuParrentString = "B";
    menu[3]._callbackFunc = B1Callback;
    _subMenuB.push_back(menu[3]);

    menu[4]._subMenuString = "B2";
    menu[4]._mainMenuParrentString = "B";
    menu[4]._callbackFunc = B2Callback;
    _subMenuB.push_back(menu[4]);

    _mainMenu.push_back(_subMenuA);
    _mainMenu.push_back(_subMenuB);
}

void UserSettings::SetStartMainMenu(void){
    _mainMenuIter = _mainMenu.begin();
    _subMenuIter = (*_mainMenuIter).begin();
    _subMenuEnd = (*_mainMenuIter).end() - 1;
    _mainMenuEnd = _mainMenu.end() - 1;
    _actSubMenuContent = (*_subMenuIter);
    _actMainMenuParrentString = _actSubMenuContent._mainMenuParrentString;
}

void UserSettings::A1Callback(void){trace_printf("Inside function %s\n", __PRETTY_FUNCTION__);}
void UserSettings::A2Callback(void){trace_printf("Inside function %s\n", __PRETTY_FUNCTION__);}
void UserSettings::A3Callback(void){trace_printf("Inside function %s\n", __PRETTY_FUNCTION__);}

void UserSettings::B1Callback(void){trace_printf("Inside function %s\n", __PRETTY_FUNCTION__);}
void UserSettings::B2Callback(void){trace_printf("Inside function %s\n", __PRETTY_FUNCTION__);}

}
