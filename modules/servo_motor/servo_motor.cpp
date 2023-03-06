//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "alarm.h"

#include "servo_motor.h"

//=====[Declaration of private defines]========================================

#define DUTY_SPIN               0.015
#define DUTY_STOP               0
#define PERIOD                  0.02
#define TIME                    20000


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut servo(PF_9);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void servoMotorUpdate()

{   servo.period(PERIOD); //set period to 20ms

    if (alarmState){ //if alarmState = TRUE 
    servo.write (DUTY_SPIN); //servo motor spins 
    delay (TIME); //allowed time for blanket to move off bed
    servo.write (DUTY_STOP); //servo motor stops 
    }
}
