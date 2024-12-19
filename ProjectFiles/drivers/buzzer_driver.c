#include "buzzer_driver.h"
#include "pico/stdlib.h"

void buzzer_init(uint buzzer_pin) {
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
}

// Turn on the buzzer
void buzzer_on(uint buzzer_pin) {
    gpio_put(buzzer_pin, 1);
}

// Turn off the buzzer
void buzzer_off(uint buzzer_pin) {
    gpio_put(buzzer_pin, 0);
}

// Toggle the buzzer
void buzzer_toggle(uint buzzer_pin) {
    gpio_put(buzzer_pin, !gpio_get(buzzer_pin));
}

