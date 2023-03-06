//=====[Libraries]=============================================================

#include "arm_book_lib.h"//changed this for dylan:)))))

#include "alarm_clock_system.h"

#include "alarm.h"
#include "user_interface.h"
#include "fire_alarm.h"
#include "pc_serial_com.h"
#include "ir_sensor.h"
#include "servo_motor.h"
#include "light_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void alarmClockSystemInit()
{
    userInterfaceInit(); //keep
    alarmInit();// keep
    pcSerialComInit();//keep
    motorControlInit();//motor sensor Initial 
    lightControlInit();//might keep
}

void alarmClockSystemUpdate()
{
    userInterfaceUpdate();
    alarmUpdate();
    pcSerialComUpdate();
    motorControlUpdate();
    lightControlUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
