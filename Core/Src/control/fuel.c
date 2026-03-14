#include "control/fuel.h"
#include "control/interpolation.h"
#include "control/enriquecimiento/e_arranque.h"
#include "control/fuel_table.h"
#include "sensores/sensores.h"
#include "control/enriquecimiento/e_frioralenty.h"


/* variable global visible para el debugger */
extern volatile uint16_t tiempo_base_pw;
volatile uint16_t tiemp_base_pw = 0;
volatile uint16_t tiempo_final_pw = 0;
/*
 * Calcula el tiempo de apertura del inyector
 * usando estrategia Alpha-N (RPM vs TPS)
 */
/*
Calcula el tiempo de apertura del inyector
usando estrategia Alpha-N (RPM vs TPS)
*/
// Esta es la funcion principal de calculo de gasolina

uint16_t fuel_calculate_pw(uint16_t rpm, uint8_t tps)
{
    uint16_t base_pw;
    uint16_t final_pw;

    /* 1️⃣ combustible base desde la tabla RPM vs TPS */

    base_pw = tabla_rpm_tps(rpm, tps);

    tiemp_base_pw = base_pw;


    /* 2️⃣ enriquecimiento de arranque */

    if (rpm < 400)
    {
        base_pw = enrichment_cranking_apply(base_pw, sensors.temp_engine);
    }


    /* 3️⃣ enriquecimiento en frío durante calentamiento */

    base_pw = enrichment_frioralenty_apply(base_pw, sensors.temp_engine);


    /* 4️⃣ resultado final */

    final_pw = base_pw;

    tiempo_final_pw = final_pw;

    return final_pw;
}




