#include "led_driver.h"
#include "pico/stdlib.h"

void led_init(uint led_pin) {
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
}

// Turn on the LED
void led_on(uint led_pin) {
    gpio_put(led_pin, 1);
}

// Turn off the LED
void led_off(uint led_pin) {
    gpio_put(led_pin, 0);
}

// Toggle the LED state
void led_toggle(uint led_pin) {
    gpio_put(led_pin, !gpio_get(led_pin));
}

