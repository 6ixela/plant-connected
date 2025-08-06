#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int adc_channel;
    int adc_width;
    int adc_attenuation;
} sensor_t;

bool sensor_create(sensor_t* sensor, int adc_channel, int adc_width, int adc_attenuation);

int sensor_read(sensor_t* sensor);

#endif // SENSOR_H