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
      std::string _subMenuString;
      std::string _mainMenuParrentString;
      std::function<void(void)> _callbackFunc;
  };
public:  
  static void Init(void);
  static std::string GetNextMainMenuString(void);
  static std::string GetCurrentMainMenuString(void);
  static std::string GetNextSubMenuString(void);
  static std::string GetCurrentSubMenuString(void);
  static void SetStartMainMenu(); 
  static void CallSubMenuFunction(void);
#if DEVELOP
  static void TestUserSettings(void);
#endif
  
private:
  static void A1Callback(void);
  static void A2Callback(void);
  static void A3Callback(void);
  
  static void B1Callback(void);
  static void B2Callback(void);
  
  typedef std::vector<SubMenuContent> SubMenuQueueType;
  typedef std::vector<SubMenuQueueType> MainMenuQueueType;
  
  
  static MainMenuQueueType _mainMenu;
  static SubMenuQueueType _subMenuA;
  static SubMenuQueueType _subMenuB;
  
  static MainMenuQueueType::iterator _mainMenuIter;
  static MainMenuQueueType::iterator _mainMenuEnd;
  static SubMenuQueueType::iterator _subMenuIter;
  static SubMenuQueueType::iterator _subMenuEnd;
  static SubMenuContent _actSubMenuContent;
  static std::string _actMainMenuParrentString;
};

}

#endif /* APPLICATION_USERSETTINGS_H_ */
