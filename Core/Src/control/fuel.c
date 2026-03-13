#include "control/fuel.h"
#include "control/interpolation.h"
#include "debug/debug.h"

/*
 * Calcula el tiempo de apertura del inyector
 * usando estrategia Alpha-N (RPM vs TPS)
 */

uint16_t fuel_calculate_pw(uint16_t rpm, uint8_t tps)
{
    uint16_t base_pw;

    /* obtener valor interpolado desde la tabla */
    base_pw = interpolate_2d(rpm, tps);

    /* variables para Live Expressions */
    debug.injection_pw = base_pw;
    debug.rpm = rpm;
    debug.tps = tps;

    return base_pw;
}
