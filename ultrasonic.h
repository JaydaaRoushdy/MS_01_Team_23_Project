#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

//left front
#define ECHO_PIN_LF 1
#define TRIG_PIN_LF 0  

//left back 
#define ECHO_PIN_LB 5 
#define TRIG_PIN_LB 4 

//front
#define ECHO_PIN_F 17 //D5  
#define TRIG_PIN_F 18 //D6  

//back 
#define ECHO_PIN_B 16 //D4  
#define TRIG_PIN_B 25 //D2 

void ultrasonic_init(void);

float measure_distance_left_front();

float measure_distance_left_back();

float measure_distance_front();

float measure_distance_back();

float measure_distance();

#endif 
