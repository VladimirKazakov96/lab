/**
  *
  * @file           : usart_utilities.h
  * @brief          :
  */

#ifndef __USART_UTILITIES_H
#define __USART_UTILITIES_H

#include "stm32f4xx_hal.h"

uint8_t* USART_TransmitReceive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);


#endif /* __USART_UTILITIES_H */
