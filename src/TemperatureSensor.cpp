#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
{
    this->period_ms = defaultPeriod;
    this->data = defaultMeasurementData;
}

TemperatureSensor::TemperatureSensor(unsigned int var)
{
    this->period_ms = var;
    this->data = defaultMeasurementData;
}

TemperatureSensor::~TemperatureSensor()
{

}

ret_t TemperatureSensor::getData(float &data)
{
    data = this->data;
    return RETURN_OK;
}

void TemperatureSensor::setPeriod(unsigned int var)
{
    this->period_ms = var;
}