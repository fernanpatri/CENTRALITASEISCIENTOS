#include "control/enriquecimiento/e_frioralenty.h"

/*
Enriquecimiento de mezcla durante el calentamiento del motor
(warmup enrichment / cold idle enrichment)
*/

/* variable para ver en debugger */

volatile uint16_t frioralenty_enrich_percent = 100;


/* eje de temperatura del motor */

static const int8_t frioralenty_temp_axis[8] =
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

static const uint16_t frioralenty_enrichment_table[8] =
{
    180,   // -10°C
    160,   // 0°C
    145,   // 10°C
    130,   // 20°C
    120,   // 30°C
    110,   // 40°C
    105,   // 60°C
    100    // 80°C
};


/* obtiene enriquecimiento interpolado */

uint16_t enrichment_frioralenty_get(int16_t temp)
{
    uint8_t i;

    if (temp <= frioralenty_temp_axis[0])
        return frioralenty_enrichment_table[0];

    if (temp >= frioralenty_temp_axis[7])
        return frioralenty_enrichment_table[7];

    for (i = 0; i < 7; i++)
    {
        if (temp < frioralenty_temp_axis[i+1])
        {
            int16_t t1 = frioralenty_temp_axis[i];
            int16_t t2 = frioralenty_temp_axis[i+1];

            uint16_t e1 = frioralenty_enrichment_table[i];
            uint16_t e2 = frioralenty_enrichment_table[i+1];

            return e1 + ((temp - t1) * (e2 - e1)) / (t2 - t1);
        }
    }

    return frioralenty_enrichment_table[7];
}


/* aplica enriquecimiento */

uint16_t enrichment_frioralenty_apply(uint16_t base_pw, int16_t temp)
{
    frioralenty_enrich_percent = enrichment_frioralenty_get(temp);

    return (base_pw * frioralenty_enrich_percent) / 100;
}
