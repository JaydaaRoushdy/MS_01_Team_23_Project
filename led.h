#ifndef LED_H
#define LED_H

#define RED_LED_PIN 14 
#define GREEN_LED_PIN 28 //D16
#define YELLOW_LED_PIN 29 //D17

void led_init();

void led_red_on();

void led_green_on();

void led_yellow_on();

void leds_on();

void leds_off();

void led_red_off();

void led_green_off();

void led_yellow_off();


#endif