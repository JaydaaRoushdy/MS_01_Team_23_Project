#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/gpio.h"

#include "hardware/irq.h"

#include "ultrasonic.h"

#include "led.h"

#include "buzzer.h"

#include "motor.h"

#include "hardware/pwm.h"



int main() {

    stdio_init_all();
    ultrasonic_init();
    led_init();
    leds_off();
    buzzer_init();
    motor_init();


    // Loop forever
    while (1) {  
        //measure the distances from the two ultrasonic sensors on the left side of the car
        float distance1 = measure_distance_left_front();
        float distance2 = measure_distance_left_back();

        //if the distances are bigger than 15cm meaning that there is a parking space available, 
        //move till you encounter an object i.e another car which we will parallel park behind
        if(distance1>15 && distance2>15){
            left_motor_drive(150, true);
            right_motor_drive(170, true);
        }
        else{
            //move the right wheel with a speed faster than the left so that the car rotates to enter the parking space
            left_motor_drive(115, false); 
            right_motor_drive(145, false);
            sleep_ms(1500);

            //maneuver the car to align itself inside the parking space
            left_motor_drive(130, false);
            right_motor_drive(0, false);
            sleep_ms(1100);


            //stop
            left_motor_drive(0, true);
            right_motor_drive(0, true);
            sleep_ms(1000);
            break; //break here so that the car stops in its parking position
        }
        
    }

}


        
 

