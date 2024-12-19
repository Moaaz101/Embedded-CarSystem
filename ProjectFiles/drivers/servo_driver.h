#ifndef SERVO_DRIVER_H
#define SERVO_DRIVER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#define SERVO_PIN 6

void servo_init(uint servo_pin);
void servo_angle(uint servo_angle, uint servo_pin);

#endif
