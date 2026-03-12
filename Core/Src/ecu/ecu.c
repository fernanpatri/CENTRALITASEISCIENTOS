
#include "main.h"
#include "ecu/ecu.h"
#include "sensores/sensores.h"
#include "control/rpm.h"

volatile uint8_t ecu_tick = 0;
static uint8_t counter_100ms = 0;
static uint16_t counter_1s = 0;

volatile float dbg_temp_engine;
volatile float dbg_temp_air;
volatile uint16_t dbg_throttle;
volatile uint32_t dbg_rpm;
volatile uint16_t dbg_throttle_percent;
void ecu_init(void)
{
	sensors_init();
}

void ecu_loop(void)
{

	/* ===== tareas cada 10 ms ===== */

	    // leer sensores DMA

	 sensors_update();

	  rpm_timeout_update();

        uint32_t rpm;

__disable_irq();
	    rpm = engine_rpm;
	    __enable_irq();

	  /* copiar valores para debug */

	    dbg_temp_engine = sensors.temp_engine;
	    dbg_temp_air = sensors.temp_air;
	    dbg_throttle = sensors.throttle_adc;
	    dbg_rpm = rpm;
	    dbg_throttle_percent = sensors.throttle_percent;

	// volatile float temp = sensors.temp_engine;
	// volatile float temp_air = sensors.temp_air;
	// volatile uint16_t throttle = sensors.throttle_adc;








	//HAL_GPIO_WritePin(DEBUG_CPU_GPIO_Port, DEBUG_CPU_Pin, GPIO_PIN_SET);

		//HAL_GPIO_WritePin(DEBUG_CPU_GPIO_Port, DEBUG_CPU_Pin, GPIO_PIN_RESET);

	    /* ===== tareas cada 100 ms ===== */

	    counter_100ms++;

	    if(counter_100ms >= 10)
	    {
	        counter_100ms = 0;


	      //  HAL_GPIO_WritePin(ECU_GPIO_Port, ECU_Pin, GPIO_PIN_SET);

	     //  HAL_GPIO_WritePin(ECU_GPIO_Port, ECU_Pin, GPIO_PIN_RESET);
	        // tareas cada 100 ms
	    }



	    /* ===== tareas cada 1 segundo ===== */

	    counter_1s++;

	    if(counter_1s >= 100)
	    {
	        counter_1s = 0;

	       // HAL_GPIO_WritePin(ECU2_GPIO_Port, ECU2_Pin, GPIO_PIN_SET);

	      // 	HAL_GPIO_WritePin(ECU2_GPIO_Port, ECU2_Pin, GPIO_PIN_RESET);
	        // tareas cada 1 segundo
	    }

	 /*HAL_GPIO_WritePin(DEBUG_CPU_GPIO_Port, DEBUG_CPU_Pin, GPIO_PIN_SET);

	   //HAL_Delay(1);   // delay de prueba

	    HAL_GPIO_WritePin(DEBUG_CPU_GPIO_Port, DEBUG_CPU_Pin, GPIO_PIN_RESET);

	 //  HAL_Delay(1	);   // delay de prueba

*/

}
