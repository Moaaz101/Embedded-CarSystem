#include "ultrasonic_driver.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"

void ultrasonic_init() {
    gpio_init(TRIG_PIN1);
    gpio_set_dir(TRIG_PIN1, GPIO_OUT);

    gpio_init(ECHO_PIN1);
    gpio_set_dir(ECHO_PIN1, GPIO_IN);

    gpio_init(TRIG_PIN2);
    gpio_set_dir(TRIG_PIN2, GPIO_OUT);

    gpio_init(ECHO_PIN2);
    gpio_set_dir(ECHO_PIN2, GPIO_IN);

}

uint ultrasonic_left_distance() {
    // Send a 10us pulse to the trigger pin
    gpio_put(TRIG_PIN1, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN1, 0);

    // Wait for the echo pin to go high
    while (gpio_get(ECHO_PIN1) == 0);

    // Start the timer
    uint32_t start_time = time_us_32();

    // Wait for the echo pin to go low
    while (gpio_get(ECHO_PIN1) == 1);

    // Stop the timer
    uint32_t end_time = time_us_32();

    // Calculate the duration of the pulse
    uint32_t pulse_duration = end_time - start_time;

    // Calculate the distance in cm
    uint distance = pulse_duration / 58;

    return distance;
}

uint ultrasonic_right_distance() {
    // Send a 10us pulse to the trigger pin
    gpio_put(TRIG_PIN2, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN2, 0);

    // Wait for the echo pin to go high
    while (gpio_get(ECHO_PIN2) == 0);

    // Start the timer
    uint32_t start_time = time_us_32();

    // Wait for the echo pin to go low
    while (gpio_get(ECHO_PIN2) == 1);

    // Stop the timer
    uint32_t end_time = time_us_32();

    // Calculate the duration of the pulse
    uint32_t pulse_duration = end_time - start_time;

    // Calculate the distance in cm
    uint distance = pulse_duration / 58;

    return distance;
}
