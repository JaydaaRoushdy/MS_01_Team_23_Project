#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/gpio.h"

#include "led.h"


int main() {

    led_init();

    // Initialize chosen serial port
    stdio_init_all();

    // Loop forever
    while (true) {
        
        //turn off all leds initially
        leds_off();
        sleep_ms(5000);
        
        //turn on the red led
        led_red_on();
        
        //sleep for 1 sec i.e keep it on for 1 sec
        sleep_ms(1000);
        
        //turn it off
        leds_off();

        //turn on the green led
        led_green_on();
        
        //sleep for 1 sec i.e keep it on for 1 sec
        sleep_ms(1000);
        
        //turn it off
        leds_off();

        //turn on the blue led
        led_blue_on();
        
        //sleep for 1 sec i.e keep it on for 1 sec
        sleep_ms(1000);
        
        //turn it off
        leds_off();

        //turn them all on together  
        leds_on();

        //keep them open for 2 seconds
        sleep_ms(2000);
        
        //then turn them all off
        leds_off();
    }
}
