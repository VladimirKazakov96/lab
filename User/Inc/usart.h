/**
  *
  * @file           : usart.h
  * @brief          :
  */

#ifndef __USART_H
#define __USART_H

#include "stm32f4xx_hal.h"

void MX_USART1_UART_Init(void);
UART_HandleTypeDef* Get_ptr_huart1();


#endif /* __USART_H */
