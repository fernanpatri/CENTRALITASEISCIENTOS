#include "main.h"
#include "sensores/sensores.h"
#include "sensores/calibracion/calibracion.h"

extern ADC_HandleTypeDef hadc1;

/* buffer DMA */
static volatile uint16_t adc_buffer[3];


/* flag de inicialización del filtro */
static uint8_t sensors_initialized = 0;
/* estructura de sensores */
SensorData sensors;

/* inicialización del ADC con DMA */

void sensors_init(void)
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);

    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buffer, 3);
}

/* actualización de sensores */

void sensors_update(void)
{
    /* leer valores ADC */

    sensors.temp_engine = adc_buffer[0];
    sensors.temp_air = adc_buffer[1];
    sensors.throttle = adc_buffer[2];

    /* filtro exponencial */

    /* inicialización del filtro */

       if(!sensors_initialized)
       {
           sensors.throttle_filtered = sensors.throttle;
           sensors_initialized = 1;
       }
       else
       {
           int32_t diff;

           diff = (int32_t)sensors.throttle - (int32_t)sensors.throttle_filtered;

           sensors.throttle_filtered =
               sensors.throttle_filtered + diff / 8;
       }
    /* conversión a porcentaje */

    if(calibration.throttle_max > calibration.throttle_min)
    {
        sensors.throttle_percent =
            100 * (sensors.throttle_filtered - calibration.throttle_min) /
            (calibration.throttle_max - calibration.throttle_min);
    }
    else
    {
        sensors.throttle_percent = 0;
    }

    /* limitar rango */

    if(sensors.throttle_percent > 100)
        sensors.throttle_percent = 100;
}
