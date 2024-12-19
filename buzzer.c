#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "buzzer.h"

// Initialize the buzzer pin
void buzzer_init() {
    gpio_init(BUZZER_PIN);                
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);   
    gpio_put(BUZZER_PIN, 0);              
}

// Turn the buzzer ON
void buzzer_on() {
    gpio_put(BUZZER_PIN, 1);              
}

// Turn the buzzer OFF
void buzzer_off() {
    gpio_put(BUZZER_PIN, 0);              
}

