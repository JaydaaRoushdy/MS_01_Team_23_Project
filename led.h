#ifndef LED_H
#define LED_H

#define RED_LED_PIN 17 //D5
#define GREEN_LED_PIN 18 //D6
#define BLUE_LED_PIN 19 //D7

void led_init();

void led_red_on();

void led_green_on();

void led_blue_on();

void leds_on();

void leds_off();


#endif