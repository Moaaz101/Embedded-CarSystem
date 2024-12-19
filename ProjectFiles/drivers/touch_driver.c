#include "touch_driver.h"
#include "pico/stdlib.h"

void touch_init(uint touch_pin) {
    gpio_init(touch_pin);
    gpio_set_dir(touch_pin, GPIO_IN);
}

bool touch_read(uint touch_pin) {
    return gpio_get(touch_pin);
}