//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "light_control.h"
#include "bright_control.h"
#include "ldr_sensor.h" 
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============
//=====[Declaration of external public global variables]=======================

static float lightControlLoopGain = 0.01;

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static float dutyCycle = 0.5f;
static float brightnessRGBLedRedFactor = 0.5f;
static float brightnessRGBLedGreenFactor = 0.5f;
static float brightnessRGBLedBlueFactor = 0.5f;

//=====[Implementations of public functions]===================================

void lightControlInit()
{
    brightControlInit();
}

void lightControlUpdate()
{   
    if (alarmState){
        dutyCycle = dutyCycle + lightControlLoopGain
                        * (ldrSensorRead());//maybe remove light level control read since 
                            //we do not have a potentiometer, 

        setDutyCycle( RGB_LED_RED, brightnessRGBLedRedFactor*dutyCycle );
        setDutyCycle( RGB_LED_GREEN, brightnessRGBLedGreenFactor*dutyCycle );
        setDutyCycle( RGB_LED_BLUE, brightnessRGBLedBlueFactor*dutyCycle );
 }
}


void lightControlBrightnessChangeRGBFactor( lightControl_t light, bool state )
{
    switch( light ) {
        case RGB_LED_RED:
            if ( state ) brightnessRGBLedRedFactor+=0.1;
                else brightnessRGBLedRedFactor-=0.1;
            if ( brightnessRGBLedRedFactor > 1) brightnessRGBLedRedFactor=1.0;
            if ( brightnessRGBLedRedFactor < 0) brightnessRGBLedRedFactor=0.0; 
        break;
        case RGB_LED_GREEN:
            if ( state ) brightnessRGBLedGreenFactor+=0.1;
                else brightnessRGBLedGreenFactor-=0.1;  
            if ( brightnessRGBLedGreenFactor > 1) brightnessRGBLedGreenFactor=1.0;
            if ( brightnessRGBLedGreenFactor < 0) brightnessRGBLedGreenFactor=0.0;      
        break;
        case RGB_LED_BLUE:
            if ( state ) brightnessRGBLedBlueFactor+=0.1;
                else brightnessRGBLedBlueFactor-=0.1;   
            if ( brightnessRGBLedBlueFactor > 1) brightnessRGBLedBlueFactor=1.0;
            if ( brightnessRGBLedBlueFactor < 0) brightnessRGBLedBlueFactor=0.0;
        break;
        default:
        break;
    }
}

//=====[Implementations of private functions]==================================
