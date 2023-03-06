#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#pragma once

#include "util.h"

/* Default values for testing purposes */
constexpr unsigned int defaultPeriod = 750;
constexpr float defaultMeasurementData = static_cast<float>(12.3f);
constexpr unsigned int defaultTemperatureSensorId = 0xFFFFFFFF; // Invalid Id as default


constexpr unsigned int TEMP_SENSOR_STATUS_REGISTER = 0x00;
constexpr unsigned int TEMP_SENSOR_CONTROL_REGISTER = 0x02;
constexpr unsigned int TEMP_SENSOR_ID_REGISTER = 0x04;
constexpr unsigned int TEMP_SENSOR_DATA_REGISTER = 0x08;
constexpr unsigned int TEMP_SENSOR_PERIOD = 0x09;
constexpr unsigned int TEMP_SENSOR_HIGH_LEVEL = 0x0D;
constexpr unsigned int TEMP_SENSOR_LOW_LEVEL = 0x11;
constexpr unsigned int TEMP_SENSOR_OUTSIDE_LIMITS = 0xFFFFFFFF;
class TemperatureSensor
{
public:
    /* Id of sensor for testing purposes */      
    unsigned int id;

    /* For startup routines */
    ret_t init(unsigned int, unsigned int, unsigned int);
    ret_t testConnection();

    /* Necassary set, gets for attributes*/
    ret_t getData(unsigned char &);
    ret_t setPeriod(unsigned int);
    ret_t setHighLevel(unsigned int);
    ret_t setLowLevel(unsigned int);
    alarm_t getAlarmStatus();   

    /* Sample conversion method wrt sensor specs */
    unsigned int convertCelcius(float);

    /* constructor and destructor */
    TemperatureSensor();    
    ~TemperatureSensor();

private:
    unsigned char data;
    unsigned int period;
    
    /* Disable the sensor for low power etc. */
    ret_t deInit();

    /* Physical layer for memory mapped ops, accesing device registers */
    ret_t read(unsigned char*, unsigned int, unsigned int);
    ret_t write(unsigned char*, unsigned int, unsigned int);
};

#endif