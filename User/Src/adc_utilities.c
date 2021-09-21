#include "adc_utilities.h"
#include "adc.h"

uint32_t Measure_voltage(){
	float val_adc = 0;
	static uint32_t dbg_m_val_adc[DBG_M_SIZE];
	static uint32_t sum = 0;
	static uint32_t ave_val = 0;
	static uint16_t i = 0;

	ADC_HandleTypeDef *ptr_hadc1 = Get_ptr_hadc1();
	if (i != DBG_M_SIZE){
		HAL_ADC_Start(ptr_hadc1);
		HAL_ADC_PollForConversion(ptr_hadc1,100);
		val_adc = 3278.5/4095*HAL_ADC_GetValue(ptr_hadc1);
		HAL_ADC_Stop(ptr_hadc1);
		dbg_m_val_adc[i] = val_adc;
		sum+=dbg_m_val_adc[i];
		i++;
	}
	else{
		ave_val = sum/DBG_M_SIZE;
		i = 0;
		sum = 0;
	}
	return ave_val;

}

