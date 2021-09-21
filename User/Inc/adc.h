/**
  *
  * @file           : adc.h
  * @brief          :
  */

#ifndef __ADC_H
#define __ADC_H

#include "stm32f4xx_hal.h"

void MX_ADC1_Init(void);
ADC_HandleTypeDef* Get_ptr_hadc1();

#endif /* __ADC_H */
