/*
 * Delay.h
 *
 *  Created on: 24.11.2016
 *      Author: t.linz
 */

#ifndef DELAY_H_
#define DELAY_H_

#include <stdint.h>

namespace Tools {

class Timing {
public:
  static volatile uint32_t gvu32SysTickCnt;  
  static void WaitMs(uint32_t u32MsToWait);
  static void WaitSec(uint8_t u8SecToWait){ WaitMs(static_cast<uint32_t>(1000 * u8SecToWait)); }
};

}

#endif /* DELAY_H_ */
