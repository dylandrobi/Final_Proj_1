//=====[Libraries]=============================================================

#include "mbed.h" //what should functions had been here?
#include "arm_book_lib.h"

#include "user_interface.h"

#include "alarm.h"
#include "alarm_clock_system.h"
#include "date_and_time.h"
#include "motion_sensor.h"
#include "siren.h"
#include "display.h"
#include "GLCD_alarm.h"
#include "servo_motor.h"

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_REPORT_MS 1000
#define DISPLAY_REFRESH_TIME_ALARM_MS 300

//=====[Declaration of private data types]=====================================

typedef enum {
    DISPLAY_ALARM_STATE,
    DISPLAY_REPORT_STATE
} displayState_t;

//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

static displayState_t displayState = DISPLAY_REPORT_STATE;
static int displayFireAlarmGraphicSequence = 0; // delete
static int displayIntruderAlarmGraphicSequence = 0; //delete
static int displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;//



//=====[Declarations (prototypes) of private functions]========================


static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfaceDisplayReportStateInit();
static void userInterfaceDisplayReportStateUpdate();
static void userInterfaceDisplayAlarmStateInit();
static void userInterfaceDisplayAlarmStateUpdate();



//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    userInterfaceDisplayReportStateInit()
    userInterfaceDisplayInit();
    userInterfaceDisplayAlarmStateInit()
} 

void userInterfaceUpdate()
{
    userInterfaceDisplayUpdate()
    userInterfaceDisplayAlarmStateUpdate()
    userInterfaceDisplayReportStateUpdate()


//=====[Implementations of private functions]==================================

static void userInterfaceDisplayReportStateInit()//displays on the LCD screen all the time 
{
    displayState = DISPLAY_REPORT_STATE;
    displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;

    displayModeWrite( DISPLAY_MODE_CHAR );

    displayClear();

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Time:" );


    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Alarm:" );
}

static void userInterfaceDisplayReportStateUpdate()//display current time and if the alarm is activated 
{
    char alarmTimeString[3] = "";

    sprintf(alarmTimeString,DateAndTimeRead());
    displayCharPositionWrite ( 12,0 );
    displayStringWrite( alarmTimeString);
  
    displayCharPositionWrite ( 6,1 );

    if ( alarmState() ) {
        displayStringWrite( " ON" );
    } else {
        displayStringWrite( " OFF" );
    }
}

static void userInterfaceDisplayAlarmStateInit()
{
    displayState = DISPLAY_ALARM_STATE;
    displayRefreshTimeMs = DISPLAY_REFRESH_TIME_ALARM_MS;

    displayClear();

    displayModeWrite( DISPLAY_MODE_GRAPHIC );

    displayFireAlarmGraphicSequence = 0;
}

static void userInterfaceDisplayAlarmStateUpdate()//updates the alarm state
{
    if ( alarmState() ) {
        switch( displayAlarmGraphicSequence ) {
        case 0:
            displayBitmapWrite( GLCD_alarm[0] );
            displayAlarmGraphicSequence++;
            break;
        case 1:
            displayBitmapWrite( GLCD_alarm[1] );
            displayAlarmGraphicSequence++;
            break;
        case 2:
            displayBitmapWrite( GLCD_alarm[2] );
            displayAlarmGraphicSequence++;
            break;
        case 3:
            displayBitmapWrite( GLCD_alarm[3] );
            displayAlarmGraphicSequence = 0;
            break;
        default:
            displayBitmapWrite( GLCD_ClearScreen );
            displayAlarmGraphicSequence = 0;
            break;
        }
}
}

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_TYPE_GLCD_ST7920, DISPLAY_CONNECTION_SPI );
    userInterfaceDisplayReportStateInit();
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;

    if( accumulatedDisplayTime >=
        displayRefreshTimeMs ) {

        accumulatedDisplayTime = 0;

        switch ( displayState ) {
        case DISPLAY_REPORT_STATE:
            userInterfaceDisplayReportStateUpdate();

            if ( alarmStateRead() ) {
                userInterfaceDisplayAlarmStateInit();
            }
            break;

        case DISPLAY_ALARM_STATE:
            userInterfaceDisplayAlarmStateUpdate();

            if ( !alarmStateRead() ) {
                userInterfaceDisplayReportStateInit();
            }
            break;

        default:
            userInterfaceDisplayReportStateInit();
            break;
        }

    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;
    }
}

