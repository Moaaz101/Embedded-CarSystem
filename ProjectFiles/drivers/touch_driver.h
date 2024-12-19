#ifndef TOUCH_DRIVER_H
#define TOUCH_DRIVER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#define TOUCH_PIN 25

void touch_init(uint touch_pin);
bool touch_read(uint touch_pin);

#endif // LED_DRIVER_H
