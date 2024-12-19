#include "pico/stdlib.h"
#include <stdio.h>
#include "ultrasonic.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

void ultrasonic_init(void){
    //left front
    gpio_init(TRIG_PIN_LF);
    gpio_set_dir(TRIG_PIN_LF, GPIO_OUT);
    gpio_put(TRIG_PIN_LF, 0);

    gpio_init(ECHO_PIN_LF);
    gpio_set_dir(ECHO_PIN_LF, GPIO_IN);

    //left back
    gpio_init(TRIG_PIN_LB);
    gpio_set_dir(TRIG_PIN_LB, GPIO_OUT);
    gpio_put(TRIG_PIN_LB, 0);

    gpio_init(ECHO_PIN_LB);
    gpio_set_dir(ECHO_PIN_LB, GPIO_IN);

    //front
    gpio_init(TRIG_PIN_F);
    gpio_set_dir(TRIG_PIN_F, GPIO_OUT);
    gpio_put(TRIG_PIN_F, 0);

    gpio_init(ECHO_PIN_F);
    gpio_set_dir(ECHO_PIN_F, GPIO_IN);

    //back
    gpio_init(TRIG_PIN_B);
    gpio_set_dir(TRIG_PIN_B, GPIO_OUT);
    gpio_put(TRIG_PIN_B, 0);

    gpio_init(ECHO_PIN_B);
    gpio_set_dir(ECHO_PIN_B, GPIO_IN);
}

float measure_distance_left_front() {
    // Trigger the sensor
    gpio_put(TRIG_PIN_LF, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN_LF, 0);

    // Wait for the echo to go HIGH
    while (gpio_get(ECHO_PIN_LF) == 0) {
        tight_loop_contents();
    }

    // Measure the HIGH time
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN_LF) == 1) {
        tight_loop_contents();
    }
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration in microseconds
    int64_t pulse_time = absolute_time_diff_us(start_time, end_time);

    // Calculate distance (in cm)
    float distance = (pulse_time * 0.0343f) / 2.0f;

    return distance;
}

float measure_distance_left_back() {
    // Trigger the sensor
    gpio_put(TRIG_PIN_LB, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN_LB, 0);

    // Wait for the echo to go HIGH
    while (gpio_get(ECHO_PIN_LB) == 0) {
        tight_loop_contents();
    }

    // Measure the HIGH time
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN_LB) == 1) {
        tight_loop_contents();
    }
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration in microseconds
    int64_t pulse_time = absolute_time_diff_us(start_time, end_time);

    // Calculate distance (in cm)
    float distance = (pulse_time * 0.0343f) / 2.0f;

    return distance;
}

float measure_distance_front() {
    // Trigger the sensor
    gpio_put(TRIG_PIN_F, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN_F, 0);

    // Wait for the echo to go HIGH
    while (gpio_get(ECHO_PIN_F) == 0) {
        tight_loop_contents();
    }

    // Measure the HIGH time
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN_F) == 1) {
        tight_loop_contents();
    }
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration in microseconds
    int64_t pulse_time = absolute_time_diff_us(start_time, end_time);

    // Calculate distance (in cm)
    float distance = (pulse_time * 0.0343f) / 2.0f;

    return distance;
}

float measure_distance_back() {
    // Trigger the sensor
    gpio_put(TRIG_PIN_B, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN_B, 0);

    // Wait for the echo to go HIGH
    while (gpio_get(ECHO_PIN_B) == 0) {
        tight_loop_contents();
    }

    // Measure the HIGH time
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN_B) == 1) {
        tight_loop_contents();
    }
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration in microseconds
    int64_t pulse_time = absolute_time_diff_us(start_time, end_time);

    // Calculate distance (in cm)
    float distance = (pulse_time * 0.0343f) / 2.0f;

    return distance;
}


float measure_distance() {
    // Trigger the sensor
    gpio_put(TRIG_PIN_LF, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN_LF, 0);

    // Wait for the echo to go HIGH
    while (gpio_get(ECHO_PIN_LF) == 0) {
        tight_loop_contents();
    }

    // Measure the HIGH time
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN_LF) == 1) {
        tight_loop_contents();
    }
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration in microseconds
    int64_t pulse_time = absolute_time_diff_us(start_time, end_time);

    // Calculate distance (in cm)
    float distance = (pulse_time * 0.0343f) / 2.0f;

    return distance;
}



