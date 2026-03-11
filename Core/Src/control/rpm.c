#include "control/rpm.h"

volatile uint32_t engine_rpm = 0;

static uint32_t last_capture = 0;
static uint32_t rpm_filtered = 0;
static uint32_t rpm_timeout_counter = 0;

#define TIMER_FREQ 1000000
#define PULSES_PER_REV 2

#define MIN_PERIOD 200
#define MAX_PERIOD 1000000

#define RPM_FILTER 4

void rpm_init(void)
{
    last_capture = 0;
    engine_rpm = 0;
    rpm_filtered = 0;
}

void rpm_capture_callback(uint32_t capture)
{
    uint32_t diff;
    uint32_t rpm_raw;
    int32_t filter_diff;

    diff = capture - last_capture;
    last_capture = capture;

    rpm_timeout_counter = 0;

    if(diff < MIN_PERIOD || diff > MAX_PERIOD)
        return;

    rpm_raw = (TIMER_FREQ * 60) / (diff * PULSES_PER_REV);

    filter_diff = (int32_t)rpm_raw - (int32_t)rpm_filtered;

    rpm_filtered =
        rpm_filtered + filter_diff / RPM_FILTER;

    engine_rpm = rpm_filtered;
}


void rpm_timeout_update(void)
{
    rpm_timeout_counter++;

    if(rpm_timeout_counter > 20)   // 20 * 10 ms = 200 ms
    {
        engine_rpm = 0;
        rpm_filtered = 0;
    }
}
