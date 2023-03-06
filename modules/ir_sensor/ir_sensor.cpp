//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "ir_sensor.h"
#include "pc_serial_com.h"
#include "alarm.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn noMotionDetected(D10);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static int i = 0;
static int accumulatedMotionSensing = 0;

//=====[Declarations (prototypes) of private functions]========================

static void motionDetected();
static void motionCeased();

//=====[Implementations of public functions]===================================

void irSensorInit()
{
    noMotionDetected.mode(PullUp);
    
}


bool irSensorUpdate(bool alarmState)
{
// check if the alarm is activated
    while (alarmState == ON){
// if IR sensor is blocked for 1 second, then clock it
    if (!noMotionDetected){
        accumulatedMotionSensing = accumulatedMotionSensing + 1;
        pcSerialComStringWrite("Motion has been sensed\r\n");
        delay(1000);
// if 3 consecutive seconds of IR sensor being blocked have passed, return True
    if (accumulatedMotionSensing == 3){
        pcSerialComStringWrite("Have a great day!\r\n");
        return true;
    }
    }
// if IR sensor is not being blocked, reset the clocked time back to 0
    if (noMotionDetected){
        pcSerialComStringWrite("No motion has been sensed\r\n");
        accumulatedMotionSensing = 0;
        delay(1000)
    }
    }
    
    
}

void motionSensorDeactivate()
{
    motionSensorActivated = false;
    if ( !pirState ) {
        pirOutputSignal.rise(NULL);
    }
    pcSerialComStringWrite("The motion sensor has been deactivated\r\n");
}

//=====[Implementations of private functions]==================================

static void motionDetected()
{
    pirState = ON;
    pirOutputSignal.rise(NULL);
    pirOutputSignal.fall(&motionCeased);
}

static void motionCeased()
{
    pirState = OFF;
    pirOutputSignal.fall(NULL);
    if ( motionSensorActivated ) {
        pirOutputSignal.rise(&motionDetected);
    }
}