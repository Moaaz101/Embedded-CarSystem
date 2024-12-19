#include <stdio.h>
#include "buzzer_driver.h"
#include "led_driver.h"
#include "servo_driver.h"
#include "ultrasonic_driver.h"
#include "touch_driver.h"
#include "ir_driver.h"
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"


// Task to handle the IR sensor and LED
void vIRTask(void *pvParameters) {
    while (true) {
        if (ir_read(IR_PIN)) {
            led_on(LED_PIN);
        } else {
            led_off(LED_PIN);
        }
        vTaskDelay(pdMS_TO_TICKS(100)); // Run every 100ms
    }
}

// Task to handle the touch sensor and servo motor
void vTouchTask(void *pvParameters) {
    while (true) {
        if (touch_read(TOUCH_PIN)) {
            servo_angle(90, SERVO_PIN); // Move servo to 90 degrees
            vTaskDelay(pdMS_TO_TICKS(5000)); // Wait for 5 seconds
        } else {
            servo_angle(180, SERVO_PIN); // Move servo back to 180 degrees
        }
        vTaskDelay(pdMS_TO_TICKS(100)); // Run every 100ms
    }
}

// Task to handle the ultrasonic sensor and buzzer
void vUltrasonicTask(void *pvParameters) {
    while (true) {
        uint left_distance = ultrasonic_left_distance();
        uint right_distance = ultrasonic_right_distance();

        printf("Left Distance: %d cm\n", left_distance);
        printf("Right Distance: %d cm\n", right_distance);
        if (ultrasonic_left_distance() < 10 || ultrasonic_right_distance() < 10) {
            buzzer_toggle(BUZZER_PIN); // Toggle buzzer if distance is below threshold
        } else {
            buzzer_off(BUZZER_PIN);    // Turn off buzzer otherwise
        }
        vTaskDelay(pdMS_TO_TICKS(100)); // Run every 100ms
    }
}

int main() {
    stdio_init_all();
    led_init(LED_PIN);
    buzzer_init(BUZZER_PIN);
    servo_init(SERVO_PIN);
    ultrasonic_init();
    touch_init(TOUCH_PIN);
    ir_init(IR_PIN);
    servo_angle(180, SERVO_PIN);

    // Create FreeRTOS tasks
    xTaskCreate(vIRTask, "IR Task", 256, NULL, 2, NULL);
    xTaskCreate(vTouchTask, "Touch Task", 256, NULL, 1, NULL);
    xTaskCreate(vUltrasonicTask, "Ultrasonic Task", 256, NULL, 3, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // Should never reach here
    while (true) {}
}
