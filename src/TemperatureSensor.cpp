#include "TemperatureSensor.h"

ret_t TemperatureSensor::init(unsigned int period, unsigned int highLevel, unsigned lowLevel)
{   
    return setPeriod(period) | setHighLevel(highLevel) | setLowLevel(lowLevel);        
}

ret_t TemperatureSensor::testConnection(){
    if(RETURN_OK == read((unsigned char *) &id, 4, TEMP_SENSOR_ID_REGISTER)){
        if(id != defaultTemperatureSensorId){
            return RETURN_OK;
        }
    }

    return RETURN_ERROR;
}

ret_t TemperatureSensor::getData(unsigned char &Data)
{
    if(RETURN_OK == read((unsigned char *) &data, 1, TEMP_SENSOR_DATA_REGISTER)){
        Data = data;
        return RETURN_OK;
    }
    
    return RETURN_ERROR;    
}

ret_t TemperatureSensor::setPeriod(unsigned int var)
{
    if(RETURN_OK == write((unsigned char *) &var, 4, TEMP_SENSOR_PERIOD)){
        period = var;
        return RETURN_OK;
    }
    
    return RETURN_ERROR;
}

ret_t TemperatureSensor::setHighLevel(unsigned int level)
{    
    if(RETURN_OK == write((unsigned char *) &level, 4, TEMP_SENSOR_HIGH_LEVEL)){
        return RETURN_OK;
    }
    
    return RETURN_ERROR;
}

ret_t TemperatureSensor::setLowLevel(unsigned int level)
{    
    if(RETURN_OK == write((unsigned char *) &level, 4, TEMP_SENSOR_LOW_LEVEL)){
        return RETURN_OK;
    }
    
    return RETURN_ERROR;
}

alarm_t TemperatureSensor::getAlarmStatus(){
    unsigned int statusRegister;
    if(RETURN_OK == read((unsigned char *) &statusRegister, 2, TEMP_SENSOR_STATUS_REGISTER)){
        if((statusRegister >> 2) && 0x01){
            if((statusRegister >> 3) && 0x01){
                return ALARM_HIGH;
            }                
            else{
                return ALARM_LOW;
            }    
        }
        else{
            return NO_ALARM;
        }        
    }
    
    return ALARM_ERROR;
}   

unsigned int TemperatureSensor::convertCelcius(float celcius)
{   
    if((celcius < 72.0) && (celcius > 2.0)) // Range: 2 - 72, 8 Bit,so stepsize will be around 0.27 
        return (unsigned int) ((celcius - 2.0)/0.27); 
    else
        return TEMP_SENSOR_OUTSIDE_LIMITS;

}

ret_t TemperatureSensor::deInit(){
    unsigned char buffer[2];
    if(RETURN_OK == read(buffer, 2, TEMP_SENSOR_CONTROL_REGISTER)){
        buffer[1] &= 0xFB; //dummy bit reset
        if(RETURN_OK == write(buffer, 2, TEMP_SENSOR_CONTROL_REGISTER)){
            return RETURN_OK;
        }    
    }

    return RETURN_ERROR;
}

TemperatureSensor::TemperatureSensor()
{
    period = defaultPeriod;
    data = defaultMeasurementData;
    id = defaultTemperatureSensorId;    
}

TemperatureSensor::~TemperatureSensor()
{
    deInit();
}

ret_t TemperatureSensor::read(unsigned char*dptr, unsigned int len, unsigned int addr){
    return receivePhy(dptr, len, addr);
}

ret_t TemperatureSensor::write(unsigned char*dptr, unsigned int len, unsigned int addr){
    return sendPhy(dptr, len, addr);
}