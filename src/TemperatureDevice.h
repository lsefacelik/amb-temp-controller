#ifndef TEMPERATUREDEVICE_H
#define TEMPERATUREDEVICE_H

#include "util.h"

#pragma once

constexpr bool defaultActive = false;
constexpr unsigned int defaultTemperatureDeviceId = 0xFFFFFFFF;
constexpr unsigned int defaultPowerLevel = 0x00;

constexpr unsigned int TEMP_DEVICE_STATUS_REGISTER = 0x00;
constexpr unsigned int TEMP_DEVICE_CONTROL_REGISTER = 0x02;
constexpr unsigned int TEMP_DEVICE_ID_REGISTER = 0x04;
constexpr unsigned int TEMP_DEVICE_POWER_LEVEL = 0x08;

class TemperatureDevice
{
public:
    /* For startup routines */
    ret_t init(unsigned int);
    ret_t testConnection();
    ret_t setPowerLevel(unsigned int);

    /* Operation commands */
    ret_t run();
    ret_t stop();
    

    /* constructor and destructor */
    TemperatureDevice();
    ~TemperatureDevice();

protected:
    bool active;
    unsigned int id;
    unsigned int powerLevel;

private:
    /* Disable the device to low power etc. */
    virtual ret_t deInit();

    /* Physical layer for memory mapped ops, accesing device registers */
    virtual ret_t read(unsigned char*, unsigned int, unsigned int);
    virtual ret_t write(unsigned char*, unsigned int, unsigned int);
};

#endif