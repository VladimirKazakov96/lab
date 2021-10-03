/**
  *
  * @file           : tim.h
  * @brief          :
  */

#ifndef __TIM_H
#define __TIM_H

#include "stm32f4xx_hal.h"


TIM_HandleTypeDef* Get_ptr_htim6();
void MX_TIM6_Init(void);

#endif /* __TIM_H */
