#ifndef ULTRASONIC_DRIVER_H
#define ULTRASONIC_DRIVER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

// left ultrasonic sensor (from behind)
#define ECHO_PIN1 12 // input pin
#define TRIG_PIN1 13 // output pin

// right ultrasonic sensor
#define ECHO_PIN2 0 // input pin
#define TRIG_PIN2 1 // output pin

void ultrasonic_init();
uint ultrasonic_left_distance();
uint ultrasonic_right_distance();

#endif
