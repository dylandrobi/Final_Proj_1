//=====[Libraries]=============================================================

#include "mbed.h" ///need to compare the date and time hwere is alarm time being set 
#include "arm_book_lib.h"

#include "alarm.h"
#include "user_interface.h"
#include "siren.h"
#include "light_control.h"
#include "servo_motor.h"
#include "ir_sensor.h"
#include "pc_serial_com.h"
//include sensor, and ldr stuff maybe try to merge the fire alarm module into this 

//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================
bool alarmState;
//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============



//=====[Declarations (prototypes) of private functions]========================

static void alarmDeactivate();

//=====[Implementations of public functions]===================================

void alarmInit()//all initial functions
{
    alarmState = OFF;
    sirenInit();
    lightControlInit();
    irSensorInit(); 
}

void alarmUpdate() // when alarm is activated, buzzer, light, IR sensor and servo motor are on.  
{
    if currentTime == alarmDateAndTimeReadStr{// get right variable 
        alarmState = ON;
        sirenUpdate();
        lightControlUpdate();
        irSensorUpdate();
        servoMotorUpdate();
    else{
        alarmState = OFF;
        }
    }
}


//=====[Implementations of private functions]==================================

static void alarmDeactivate()//When motion is sensed for twenty seconds alarm is deactivated and
                            //buzzer is off. 
{
    if (bool irSensorUpdate(bool alarmState) == true){
        alarmState = OFF;
        sirenPin.input();
    }
      
}
}

