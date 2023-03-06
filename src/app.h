#ifndef APP_H
#define APP_H

#include "TemperatureSensor.h"
#include "TemperatureDevice.h"
#include "Cooler.h"
#include "Heater.h"
#include "conf.h"
#include "util.h"

/*
    App States
    DEFAULT      : Initial state
    INIT         : Init done
    NORMAL       : NO_ALARM
    LOW_LIMIT_OP : ALARM due to low temperature, trying to raise temp
    HIGH_LIMIT_OP: ALARM due to high temperature, trying to reduce temp
    STANDBY      : System is not working
*/

typedef enum{
    DEFAULT = 0,
    INIT,
    NORMAL_OP,
    LOW_LIMIT_OP,
    HIGH_LIMIT_OP,
    STANDBY,
}statusAmbTempController_t;

#define MAX_CONSECUTIVE_ALARM_COUNT 15

void appInit(ret_t &, TemperatureSensor &, Cooler &, Heater &);
void appTest(ret_t &, TemperatureSensor &, Cooler &, Heater &);
ret_t appMain(statusAmbTempController_t &, alarm_t &, unsigned char &, TemperatureSensor &, Cooler &, Heater &);

#endif