/*
 * HW_USART.h
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#ifndef HARDWARE_HW_USART_H_
#define HARDWARE_HW_USART_H_

#include "stm32f10x_usart.h"

namespace Hardware {

class HW_USART {
    public:
        static void Init(void);
        static void Transmit(uint8_t* pData, uint8_t length);
};

}

#endif /* HARDWARE_HW_USART_H_ */
