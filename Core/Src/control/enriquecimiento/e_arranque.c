#include "control/enriquecimiento/e_arranque.h"


/*
Tabla de enriquecimiento de arranque
valores en porcentaje

temp_index debe venir del sensor de temperatura
ya convertido a índice de tabla
*/




static const uint16_t cranking_enrichment_table[8] =
{
    300,   // -10C
    260,   // 0C
    220,   // 10C
    190,   // 20C
    160,   // 30C
    140,   // 40C
    120,   // 60C
    110    // 80C
};



/* devuelve porcentaje de enriquecimiento */

uint16_t enrichment_cranking_get(uint8_t temp_index)
{
    if (temp_index > 7)
        temp_index = 7;

    return cranking_enrichment_table[temp_index];
}
// aplica enriquecimiento
uint16_t enrichment_cranking_apply(uint16_t base_pw, uint8_t temp_index)
{
    cranking_enrich_percent = enrichment_cranking_get(temp_index);

    return (base_pw * cranking_enrich_percent) / 100;
}

