#ifndef SENSOR_H
#define SENSOR_H

#include <cstdint>


enum SENSOR_TYPE {
    LIGHT,
    MOISTURE
};

// need to know if it's input or output + GPIO

typedef struct {
    enum SENSOR_TYPE type;
    int gpio_num;
} sensor_t;

void sensor_init(sensor_t *sensor, enum SENSOR_TYPE type, int gpio_num);

uint16_t sensor_read_moisture(void);
uint16_t sensor_read_light(void);

#endif /* SENSOR_H */