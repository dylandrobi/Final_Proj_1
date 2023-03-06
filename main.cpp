//=====[Libraries]=============================================================

#include "alarm_clock_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    alarmClockSystemInit();
    while (true) {
        alarmClockSystemUpdate();
    }
}
