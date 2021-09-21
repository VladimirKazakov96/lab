/**
  *
  * @file           : dac.h
  * @brief          :
  */

#ifndef __DAC_H
#define __DAC_H

#include "stm32f4xx_hal.h"

void MX_DAC_Init();

DAC_HandleTypeDef* Get_ptr_hdac();

#endif /* __DAC_H */
