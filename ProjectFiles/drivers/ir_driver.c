#include "ir_driver.h"
#include "pico/stdlib.h"

void ir_init(uint ir_pin) {
    gpio_init(ir_pin);
    gpio_set_dir(ir_pin, GPIO_IN);
    gpio_pull_up(ir_pin);
}

uint ir_read(uint ir_pin) {
    return gpio_get(ir_pin);
}