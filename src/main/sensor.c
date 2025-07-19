#include "sensor.h"

#include "driver/adc.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define SENSOR_GPIO_LIGHT 12
#define SENSOR_GPIO_MOISTURE 13

void sensor_init(sensor_t *sensor, enum SENSOR_TYPE type, int gpio_num) {
    sensor->type = type;
    sensor->gpio_num = gpio_num;

    gpio_set_direction(gpio_num,  GPIO_MODE_INPUT);
    
}