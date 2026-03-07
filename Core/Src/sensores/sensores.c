#include "main.h"
#include "sensores/sensores.h"

extern ADC_HandleTypeDef hadc1;

/* buffer DMA */
static uint16_t adc_buffer[3];

SensorData sensors;

void sensors_init(void)
{
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buffer, 3);
}

void sensors_update(void)
{
    sensors.temp_engine = adc_buffer[0];
    sensors.temp_air = adc_buffer[1];
    sensors.throttle = adc_buffer[2];
}
