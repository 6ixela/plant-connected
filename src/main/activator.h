#ifndef ACTIVATOR_H
#define ACTIVATOR_H

#include <stdbool.h>

#define HIGH 1
#define LOW 0

#define GPIO_NUM_MIN 0

typedef struct {
    int pin;
    bool is_active;
} s_activtor;

int activator_create(s_activtor* activator, int pin);
void activator_on(s_activtor* activator);
void activator_off(s_activtor* activator);
bool activator_get_state(s_activtor* activator);

#endif // ACTIVATOR_H