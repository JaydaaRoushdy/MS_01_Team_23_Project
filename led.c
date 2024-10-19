#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/gpio.h"
#include "led.h"

void led_init(){
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
}

void led_red_on(){
    gpio_put(RED_LED_PIN, true);
}

void led_green_on(){
    gpio_put(GREEN_LED_PIN, true);
}

void led_blue_on(){
    gpio_put(BLUE_LED_PIN, false); //since negative logic
}

void leds_on(){
    led_red_on();
    led_green_on();
    led_blue_on();
}

void leds_off(){
    gpio_put(RED_LED_PIN, false);
    gpio_put(GREEN_LED_PIN, false);
    gpio_put(BLUE_LED_PIN, true); //since negative logic
}