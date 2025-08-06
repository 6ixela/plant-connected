#include "sensor.h"

#include <stdlib.h>
#include "driver/adc.h"
#include "esp_log.h"

#define TAG "SENSOR"

static void sensor_init(sensor_t* sensor)
{
    adc1_config_width(sensor->adc_width);
    adc1_config_channel_atten(sensor->adc_channel, sensor->adc_attenuation);
    ESP_LOGI(TAG, "Light sensor initialized on ADC channel %d", sensor->adc_channel);
}

bool sensor_create(sensor_t* sensor, int adc_channel, int adc_width, int adc_attenuation)
{
    if (sensor != NULL)
    {
        sensor->adc_channel = adc_channel;
        sensor->adc_width = adc_width;
        sensor->adc_attenuation = adc_attenuation;
        ESP_LOGI(TAG, "Light sensor created");
        sensor_init(sensor);
        return true;
    }

    ESP_LOGI(TAG, "sensor pointer is NULL");
    return false;
}


int sensor_read(sensor_t* sensor)
{
    if (sensor == NULL)
    {
        ESP_LOGE(TAG, "Sensor is NULL");
        return -1;
    }
    return adc1_get_raw(sensor->adc_channel);
}