/**
  *
  * @file           : system_config.h
  * @brief          :
  */

#ifndef __SYSTEM_CONFIG_H
#define __SYSTEM_CONFIG_H

#include "stm32f4xx_hal.h"

void SystemClock_Config(void);
void Error_Handler(void);
void assert_failed(uint8_t *file, uint32_t line);

#endif /* __SYSTEM_CONFIG_H*/
