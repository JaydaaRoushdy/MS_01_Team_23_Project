#include "pico/stdlib.h"
#include <stdio.h>
#include "motor.h"
#include "hardware/pwm.h"

void motor_init() {

    //motor 1
    gpio_init(Motor_dir1);
    gpio_set_dir(Motor_dir1, GPIO_OUT);
    gpio_init(Motor_dir2);
    gpio_set_dir(Motor_dir2, GPIO_OUT);

    gpio_set_function(Motor_pwm, GPIO_FUNC_PWM);

    uint slice = pwm_gpio_to_slice_num(Motor_pwm);

    pwm_set_wrap(slice,255);
    pwm_set_clkdiv(slice,4.0f);

    pwm_set_enabled(slice,true);

    //motor 2
    gpio_init(Motor_2_dir1);
    gpio_set_dir(Motor_2_dir1, GPIO_OUT);
    gpio_init(Motor_2_dir2);
    gpio_set_dir(Motor_2_dir2, GPIO_OUT);

    gpio_set_function(Motor_pwm2, GPIO_FUNC_PWM);

    uint slice2 = pwm_gpio_to_slice_num(Motor_pwm2);

    pwm_set_wrap(slice2,255);
    pwm_set_clkdiv(slice2,4.0f);

    pwm_set_enabled(slice2,true);

}

void left_motor_drive(uint16_t speed, bool forward){
    if(speed > 255) speed = 255;

    if(forward){
        gpio_put(Motor_dir1,0);
        gpio_put(Motor_dir2,1);
    }else{
        gpio_put(Motor_dir1,1);
        gpio_put(Motor_dir2,0);
    }

    pwm_set_gpio_level(Motor_pwm,speed);
}

void right_motor_drive(uint16_t speed, bool forward){
    if(speed > 255) speed = 255;

    if(forward){
        gpio_put(Motor_2_dir1,0);
        gpio_put(Motor_2_dir2,1);
    }else{
        gpio_put(Motor_2_dir1,1);
        gpio_put(Motor_2_dir2,0);
    }

    pwm_set_gpio_level(Motor_pwm2,speed);
}