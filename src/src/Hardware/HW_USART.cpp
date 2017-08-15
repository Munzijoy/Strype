/*
 * HW_USART.cpp
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#include "HW_USART.h"

namespace Hardware {

void HW_USART::Init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    USART_InitTypeDef initStruct;
    USART_StructInit(&initStruct);
    USART_Init(USART1, &initStruct);
    USART1->CR1 |= (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_TCIE | USART_CR1_RXNEIE);
  
    USART1->DR = 0xAA;
    
    NVIC_EnableIRQ(USART1_IRQn);
}

void HW_USART::Transmit(uint8_t* pData, uint8_t length){
  while (length > 0){
      USART_SendData(USART1, *pData);
      pData++;
      length--;
  }
}

}
