/*
 * SystemTime.h
 *
 *  Created on: 04.01.2018
 *      Author: t.linz
 */

#include <string>

#ifndef SYSTEMTIME_H_
#define SYSTEMTIME_H_

namespace Application {

class SystemTime {
public:
  static void InitSystemTimeOnline(void);
  static void SetTimeZone(std::string timeZoneString);
  static std::string GetSystemTimeString(void);
};

}

#endif /* SYSTEMTIME_H_ */
