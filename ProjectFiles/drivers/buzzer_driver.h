#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#define BUZZER_PIN 4

void buzzer_init(uint buzzer_pin);
void buzzer_on(uint buzzer_pin);
void buzzer_off(uint buzzer_pin);
void buzzer_toggle(uint buzzer_pin);

#endif
