#ifndef E_ARRANQUE_H
#define E_ARRANQUE_H

#include <stdint.h>

extern volatile uint16_t cranking_enrich_percent;

/* devuelve el porcentaje de enriquecimiento */
uint16_t enrichment_cranking_get(uint8_t temp_index);

/* aplica enriquecimiento al tiempo de inyección */
uint16_t enrichment_cranking_apply(uint16_t base_pw, uint8_t temp_index);

#endif
