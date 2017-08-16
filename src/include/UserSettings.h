/*
 * UserSettings.h
 *
 *  Created on: 16.08.2017
 *      Author: t.linz
 */

#ifndef APPLICATION_USERSETTINGS_H_
#define APPLICATION_USERSETTINGS_H_

#include <string>
#include <functional>
#include <vector>

#include "Develop.h"

namespace Application {

class UserSettings {
  struct SubMenuContent {
      std::string _displayString;
      std::function<void(uint8_t param)> _callbackFunc;
  };
public:  
  static void Init(void);
#if DEVELOP
  static void TestUserSettings(void);
#endif
  
private:
  static void A1Callback(uint8_t param);
  static void A2Callback(uint8_t param);
  static void A3Callback(uint8_t param);
  
  static void B1Callback(uint8_t param);
  static void B2Callback(uint8_t param);
  
  typedef std::vector<SubMenuContent> SubMenuQueueType;
  typedef std::vector<SubMenuQueueType> MainMenuQueueType;
  
  
  static MainMenuQueueType _mainMenu;
  static SubMenuQueueType _subMenuA;
  static SubMenuQueueType _subMenuB;
};

}

#endif /* APPLICATION_USERSETTINGS_H_ */
