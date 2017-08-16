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

#if DEVELOP
void UserSettings::TestUserSettings(void){
    MainMenuQueueType::iterator mainMenuIter = _mainMenu.begin();

    // forwards
    for (uint8_t j = 0; j < 4; j++) {

      SubMenuQueueType subMenu = *mainMenuIter;
      SubMenuQueueType::iterator subMenuIter = subMenu.begin();
      SubMenuQueueType::iterator subMenuEnd = subMenu.end()-1;

      for (uint8_t i = 0; i < 7; i++) {

        SubMenuContent test1x = (*subMenuIter);
        trace_printf("%s mit Callback %d\n", test1x._displayString.c_str(), test1x._callbackFunc);

        if (subMenuIter != subMenuEnd) {
          ++subMenuIter;
        }
        else {
        }

      }

      if (mainMenuIter != (_mainMenu.end()-1)) {
        ++mainMenuIter;
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

    menu[0]._displayString = "A1";
    menu[0]._callbackFunc = A1Callback;
    _subMenuA.push_back(menu[0]);

    menu[1]._displayString = "A2";
    menu[1]._callbackFunc = A2Callback;
    _subMenuA.push_back(menu[1]);

    menu[2]._displayString = "A3";
    menu[2]._callbackFunc = A3Callback;
    _subMenuA.push_back(menu[2]);

    menu[3]._displayString = "B1";
    menu[3]._callbackFunc = B1Callback;
    _subMenuB.push_back(menu[3]);

    menu[4]._displayString = "B2";
    menu[4]._callbackFunc = B2Callback;
    _subMenuB.push_back(menu[4]);

    _mainMenu.push_back(_subMenuA);
    _mainMenu.push_back(_subMenuB);
}

void UserSettings::A1Callback(uint8_t param){(void)param;}
void UserSettings::A2Callback(uint8_t param){(void)param;}
void UserSettings::A3Callback(uint8_t param){(void)param;}

void UserSettings::B1Callback(uint8_t param){(void)param;}
void UserSettings::B2Callback(uint8_t param){(void)param;}

}
