#ifndef IR_DRIVER_H
#define IR_DRIVER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#define IR_PIN 27

void ir_init(uint ir_pin);
uint ir_read(uint ir_pin);

#endif
