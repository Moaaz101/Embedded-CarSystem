#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#define LED_PIN 26

void led_init(uint led_pin);
void led_on(uint led_pin);
void led_off(uint led_pin);
void led_toggle(uint led_pin);

#endif // LED_DRIVER_H
