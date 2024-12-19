#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/gpio.h"
#include "led.h"

void led_init(){
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
}

void led_red_on(){
    gpio_put(RED_LED_PIN, true);
}

void led_green_on(){
    gpio_put(GREEN_LED_PIN, true);
}

void led_yellow_on(){
    gpio_put(YELLOW_LED_PIN, true); 
}

void leds_on(){
    led_red_on();
    led_green_on();
    led_yellow_on();
}

void leds_off(){
    gpio_put(RED_LED_PIN, false);
    gpio_put(YELLOW_LED_PIN, false);
    gpio_put(GREEN_LED_PIN, false);
} 

void led_red_off(){
    gpio_put(RED_LED_PIN, false);
}

void led_green_off(){
    gpio_put(GREEN_LED_PIN, false);
}

void led_yellow_off(){
    gpio_put(YELLOW_LED_PIN, false);
}