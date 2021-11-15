/**
  *
  * @file           : gpio.h
  * @brief          :
  */

#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f4xx_hal.h"

void MX_GPIO_Init(void);
GPIO_PinState Get_btn_state();

#define GREEN_LED_Pin 		GPIO_PIN_0
#define GREEN_LED_Port 		GPIOB
/*User btn*/
#define BTN_Pin 			GPIO_PIN_13
#define BTN_Port 			GPIOC
#define PWM_MEASURE_PIN 	GPIO_PIN_6
#define PWM_MEASURE_PORT	GPIOA

#endif /* __GPIO_H */
