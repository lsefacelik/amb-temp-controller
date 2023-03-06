#ifndef UTIL_H
#define UTIL_H

typedef enum{
    CELCIUS = 0,
    FAHRENHEIT,
    KELVIN,
    TOTAL_TEMPERATURE_UNITS
}temperatureUnits_t;

typedef enum{
    RETURN_OK = 0,
    RETURN_ERROR
}ret_t;

typedef enum{    
    NO_ALARM,
    ALARM_HIGH,
    ALARM_LOW,
    ALARM_ERROR
}alarm_t;

inline ret_t operator|(ret_t a, ret_t b)
{   
    return static_cast<ret_t>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));
}

void initMemPool();
void Delay(unsigned int );
ret_t sendPhy(unsigned char *, unsigned int, unsigned int);
ret_t receivePhy(unsigned char *, unsigned int, unsigned int);

#endif