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

class Wait {
public:
  Wait(void) : m_startTime(0){}
  Wait(uint32_t waitTime) : m_startTime(waitTime){}
  static volatile uint32_t gvu32SysTickCnt;  
  static void WaitMs(uint32_t u32MsToWait);
  static void WaitSec(uint8_t u8SecToWait){ WaitMs(static_cast<uint32_t>(1000 * u8SecToWait)); }
  uint32_t GetTimeDiffMilliSec(void){ return gvu32SysTickCnt - m_startTime; }
  void StartTimeMeassurement(void){ m_startTime = gvu32SysTickCnt; };
private:
  uint32_t m_startTime;
};

}

#endif /* DELAY_H_ */
