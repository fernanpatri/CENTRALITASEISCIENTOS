#ifndef FUEL_TABLE_H
#define FUEL_TABLE_H

#include <stdint.h>

#define RPM_POINTS 8
#define TPS_POINTS 8

extern const uint16_t fuel_table[RPM_POINTS][TPS_POINTS];

extern const uint16_t rpm_bins[RPM_POINTS];
extern const uint8_t tps_bins[TPS_POINTS];

#endif
