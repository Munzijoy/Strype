/*
 * HW_USART.cpp
 *
 *  Created on: 15.08.2017
 *      Author: t.linz
 */

#include "HW_USART.h"

namespace Hardware {

void HW_USART::Init(void){
          /* Bit configuration structure for GPIOA PIN9 and PIN10 */
    GPIO_InitTypeDef gpioa_init_struct;
     
    /* Enalbe clock for USART1, AFIO and GPIOA */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | 
                           RCC_APB2Periph_GPIOA, ENABLE);
 /* GPIOA PIN9 alternative function Tx */
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_9;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &gpioa_init_struct);
    /* GPIOA PIN9 alternative function Rx */
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_10;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpioa_init_struct);
  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    USART_InitTypeDef initStruct;
    initStruct.USART_BaudRate = 115200;
    initStruct.USART_WordLength = USART_WordLength_8b;
    initStruct.USART_StopBits = USART_StopBits_1;
    initStruct.USART_Parity = USART_Parity_No ;
    initStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    initStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
    USART_Init(USART1, &initStruct);
    USART1->CR1 |= (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | /*USART_CR1_TCIE |*/ USART_CR1_RXNEIE);
  
    USART1->DR = 0xAA;
    
    NVIC_EnableIRQ(USART1_IRQn);
    

}

void HW_USART::Transmit(uint8_t* pData, uint8_t length){
  while (length > 0){
    
    while(!(USART1->SR & USART_SR_TXE));
    USART_SendData(USART1, *pData);
    
    pData++;
    length--;
  }
}

}
