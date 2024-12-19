#ifndef MOTOR_H
#define MOTOR_H
#include <stdio.h>

#define Motor_pwm 11
#define Motor_dir1 12 
#define Motor_dir2 13 

#define Motor_pwm2 10 
#define Motor_2_dir1 9 
#define Motor_2_dir2 8 

void motor_init(void);

void left_motor_drive(uint16_t speed, bool forward);

void right_motor_drive(uint16_t speed, bool forward);

#endif