#include "control/fuel_table.h"

const uint16_t rpm_bins[RPM_POINTS] =
{800,1500,2000,2500,3000,3500,4000,4500};

const uint8_t tps_bins[TPS_POINTS] =
{0,10,20,40,60,80,90,100};

const uint16_t fuel_table[RPM_POINTS][TPS_POINTS] =
{
{1500,1600,1750,1950,2150,2350,2500,2650},
{1550,1700,1900,2150,2400,2650,2850,3050},
{1600,1800,2050,2350,2650,2950,3200,3450},
{1650,1900,2200,2550,2900,3250,3550,3850},
{1700,2000,2350,2750,3150,3550,3900,4250},
{1750,2100,2500,2950,3400,3850,4250,4650},
{1800,2200,2650,3150,3650,4150,4600,5050},
{1850,2300,2800,3350,3900,4450,4950,5450}
};
uint16_t tabla_rpm_tps(uint16_t rpm, uint8_t tps)
{
    uint8_t i;
    uint8_t j;

    /* buscar índice de RPM */

    for(i = 0; i < RPM_POINTS - 1; i++)
    {
        if(rpm < rpm_bins[i+1])
            break;
    }

    /* buscar índice de TPS */

    for(j = 0; j < TPS_POINTS - 1; j++)
    {
        if(tps < tps_bins[j+1])
            break;
    }

    /* devolver valor de tabla */

    return fuel_table[i][j];
}
