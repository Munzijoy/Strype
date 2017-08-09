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
  static volatile uint32_t gvs32SysTickCnt;  
  static void WaitMs(uint32_t u32TicksToWait);
};

}

#endif /* DELAY_H_ */
