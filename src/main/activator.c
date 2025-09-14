#include "activator.h"

#include <driver/gpio.h>
#include <esp_err.h> 

int activator_create(s_activtor* activator, int pin)
{
    if (activator == NULL || pin < GPIO_NUM_MIN || pin > GPIO_NUM_MAX)
    {
        return 0;
    }
    
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << pin),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    esp_err_t ret = gpio_config(&io_conf);
    if (ret == ESP_OK)
    {
        gpio_set_level(pin, LOW);
        activator->pin = pin;
        activator->is_active = false;
    }
    return ret == ESP_OK;
}

void activator_on(s_activtor* activator)
{
    if (!activator->is_active)
    {
        gpio_set_level(activator->pin, HIGH);
        activator->is_active = true;
    }
}

void activator_off(s_activtor* activator)
{
    if (activator->is_active)
    {
        gpio_set_level(activator->pin, LOW);
        activator->is_active = false;
    }
}

bool activator_get_state(s_activtor* activator)
{
    return activator->is_active;
}