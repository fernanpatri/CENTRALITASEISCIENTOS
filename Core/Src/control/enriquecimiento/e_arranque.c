#include "control/enriquecimiento/e_arranque.h"

/*
Enriquecimiento de arranque en frío
basado en temperatura del motor
*/

/* variable global para ver en debugger */
volatile uint16_t cranking_enrich_percent = 100;


/* eje de temperaturas (°C) */
static const int8_t cranking_temp_axis[8] =
{
    -10,
    0,
    10,
    20,
    30,
    40,
    60,
    80
};


/* tabla de enriquecimiento (%) */
static const uint16_t cranking_enrichment_table[8] =
{
    300,   // -10°C
    260,   // 0°C
    220,   // 10°C
    190,   // 20°C
    160,   // 30°C
    140,   // 40°C
    120,   // 60°C
    110    // 80°C
};


/* obtiene el enriquecimiento interpolado según temperatura */

uint16_t enrichment_cranking_get(int16_t temp)
{
    uint8_t i;

    /* límites de tabla */

    if (temp <= cranking_temp_axis[0])
        return cranking_enrichment_table[0];

    if (temp >= cranking_temp_axis[7])
        return cranking_enrichment_table[7];

    /* buscar intervalo */

    for (i = 0; i < 7; i++)
    {
        if (temp < cranking_temp_axis[i+1])
        {
            int16_t t1 = cranking_temp_axis[i];
            int16_t t2 = cranking_temp_axis[i+1];

            uint16_t e1 = cranking_enrichment_table[i];
            uint16_t e2 = cranking_enrichment_table[i+1];

            /* interpolación lineal */

            return e1 + ((temp - t1) * (e2 - e1)) / (t2 - t1);
        }
    }

    return cranking_enrichment_table[7];
}


/* aplica enriquecimiento al tiempo de inyección */

uint16_t enrichment_cranking_apply(uint16_t base_pw, int16_t temp)
{
    cranking_enrich_percent = enrichment_cranking_get(temp);

    return (base_pw * cranking_enrich_percent) / 100;
}
