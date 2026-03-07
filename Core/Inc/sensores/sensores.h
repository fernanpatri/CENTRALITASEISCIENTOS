#ifndef SENSORES_H
#define SENSORES_H

#include <stdint.h>

typedef struct
{
    uint16_t temp_engine;
    uint16_t temp_air;
    uint16_t throttle;

} SensorData;

extern SensorData sensors;

void sensors_init(void);
void sensors_update(void);

#endif
