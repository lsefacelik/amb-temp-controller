#ifndef CONF_H
#define CONF_H

#define MAX_REGISTER_SIZE 64

constexpr unsigned int DefaultTempReadPeriod = 235;
constexpr unsigned int DefaultCoolerPowerLevel = 0x10;
constexpr unsigned int DefaultHeaterPowerLevel = 0x15;
constexpr unsigned int DefaultHighTempLevel = 200;
constexpr unsigned int DefaultLowTempLevel = 100;
constexpr unsigned int DefaultHighTempSensitivity = 15;
constexpr unsigned int DefaultLowTempSensitivity = 25;

constexpr unsigned int ApplicationPeriod = 150;

#endif