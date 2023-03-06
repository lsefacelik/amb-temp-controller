#ifndef HEATER_H
#define HEATER_H

#include "TemperatureDevice.h"
#include "util.h"

#pragma once

constexpr unsigned int HEATER_CONTROL_REGISTER = 0x02;

class Heater: public TemperatureDevice
{
public:
    Heater();
    ~Heater();

private:
    /* Disable the device to low power etc. */
    ret_t deInit();

    /* Physical layer for memory mapped ops, accesing device registers */
    ret_t read(unsigned char*, unsigned int, unsigned int);
    ret_t write(unsigned char*, unsigned int, unsigned int);
};

#endif