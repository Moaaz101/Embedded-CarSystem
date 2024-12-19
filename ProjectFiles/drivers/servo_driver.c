#include "servo_driver.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"

void servo_init(uint servo_pin) {
    // gpio_init(servo_pin);
    // gpio_set_dir(servo_pin, GPIO_OUT);
    gpio_set_function(servo_pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(servo_pin);
    pwm_set_wrap(slice_num, 65535); // Set the wrap value for 20ms period (50Hz)
    pwm_set_clkdiv(slice_num, 38.15f); // Set the clock divider for 125MHz / 256 = 488.28125kHz
    pwm_set_enabled(slice_num, true);
}

void servo_angle(uint servo_angle, uint servo_pin) {
    uint slice_num = pwm_gpio_to_slice_num(servo_pin);
    uint duty_cycle =servo_angle*6250/180+2000; ;
    pwm_set_gpio_level(servo_pin, duty_cycle); //max 8250 min 2000
}