#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#pragma once

#include "util.h"

constexpr unsigned int defaultPeriod = 750;
constexpr float defaultMeasurementData = 12.34;

class TemperatureSensor
{
public:
    TemperatureSensor();
    TemperatureSensor(unsigned int);    
    ~TemperatureSensor();
    
    unsigned int getDataInRaw();
    float getUnitData();
    ret_t getDataInUnit(float &);
    void setPeriod(unsigned int);

private:
    unsigned int dataRaw;
    float dataUnit;
    unsigned int period;
    temperatureUnits_t unit;    
    unsigned int id;

    float getDataInFahrenheit();
    float getDataInCelcius();
    float getDataInKelvin();
};

#endif