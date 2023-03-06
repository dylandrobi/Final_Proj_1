//=====[#include guards - begin]===============================================

#ifndef _LIGHT_CONTROL_H_
#define _LIGHT_CONTROL_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
    RGB_LED_RED,
    RGB_LED_GREEN,
    RGB_LED_BLUE,
} lightControl_t;

//=====[Declarations (prototypes) of public functions]=========================

void lightControlInit();
void lightControlUpdate();
void lightControlBrightnessChangeRGBFactor( lightControl_t light, bool state );

//=====[#include guards - end]=================================================

#endif // _LIGHT_CONTROL_H_
