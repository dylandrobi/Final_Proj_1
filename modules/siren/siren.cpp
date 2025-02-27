//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "siren.h"
#include "alarm.h"

#include "alarm_clock_system.h"

//=====[Declaration of private defines]========================================
#define TIME_INCREMENT_MS           10
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalInOut sirenPin(PE_10); //buzzer is a digital input object

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
int accumulatedTimeAlarm = 0;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sirenInit() //initalize to off, declare as an open drain
{
   sirenPin.mode(OpenDrain);
   sirenPin.input();
}
void sirenUpdate() { //turns buzzer on, if alarm is on, else buzzer stays off
    if (alarmState){
       accumulatedTimeAlarm = accumulatedTimeAlarm + TIME_INCREMENT_MS;
       sirenPin.output();
       sirenPin = LOW; 
    }
    else{ 
        sirenPin.input();
    }
}

//=====[Implementations of private functions]==================================