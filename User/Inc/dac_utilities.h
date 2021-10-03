/**
  *
  * @file           : dac_utilities.h
  * @brief          :
  */

#ifndef __DAC_UTILITIES_H
#define __DAC_UTILITIES_H

#include "stm32f4xx_hal.h"

void Set_dac_volt_1st_ch(uint16_t mv);
void Set_harmonic_signal(uint16_t mv_ampl, uint16_t freq);
uint16_t Get_kf();

#endif /*__DAC_UTILITIES_H*/
