#include "control/fuel.h"
#include "control/interpolation.h"
#include "control/enriquecimiento/e_arranque.h"
#include "control/fuel_table.h"
#include "sensores/sensores.h"



/* variable global visible para el debugger */
extern volatile uint16_t tiempo_base_pw;
/*
 * Calcula el tiempo de apertura del inyector
 * usando estrategia Alpha-N (RPM vs TPS)
 */

uint16_t fuel_calculate_pw(uint16_t rpm, uint8_t tps)
{
    uint16_t base_pw;

    // obtener valor interpolado desde la tabla
    base_pw = interpolate_2d(rpm, tps);

    // copiar a variable global
       tiempo_base_pw = base_pw;


    return 	base_pw;
}


