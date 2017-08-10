/*
 * Delay.cpp
 *
 *  Created on: 24.11.2016
 *      Author: t.linz
 */

#include "Delay.h"

namespace Tools {

volatile uint32_t Timing::gvs32SysTickCnt(0);

void Timing::WaitMs(uint32_t u32MsToWait){
    volatile uint32_t u32StartTime = gvs32SysTickCnt;  
   
    bool bTimeNotExpired = true;
    do {
        volatile uint32_t actTime = gvs32SysTickCnt;
        bTimeNotExpired = ((u32StartTime + u32MsToWait ) > actTime); 
    } while(bTimeNotExpired);
}

}


