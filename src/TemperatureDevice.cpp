#include "TemperatureDevice.h"

ret_t TemperatureDevice::init(unsigned int level){
    return setPowerLevel(level);
}

ret_t TemperatureDevice::testConnection(){
    if(RETURN_OK == read((unsigned char *) &id, 4, TEMP_DEVICE_ID_REGISTER)){
        if(id != defaultTemperatureDeviceId){
            return RETURN_OK;
        }
    }

    return RETURN_ERROR;
}

ret_t TemperatureDevice::setPowerLevel(unsigned int var)
{
    if(RETURN_OK == write((unsigned char *) &var, 4, TEMP_DEVICE_POWER_LEVEL)){
        powerLevel = var;
        return RETURN_OK;
    }
    
    return RETURN_ERROR;
}

ret_t TemperatureDevice::run(){
    
    unsigned char buffer[2];
    if(RETURN_OK == read(buffer, 2, TEMP_DEVICE_CONTROL_REGISTER)){
        buffer[1] |= 0x04; //dummy bit set
        if(RETURN_OK == write(buffer, 2, TEMP_DEVICE_CONTROL_REGISTER)){
            return RETURN_OK;
        }    
    }

    return RETURN_ERROR;
}

ret_t TemperatureDevice::stop(){
    
    unsigned char buffer[2];
    if(RETURN_OK == read(buffer, 2, TEMP_DEVICE_CONTROL_REGISTER)){
        buffer[1] &= 0xFB; //dummy bit reset
        if(RETURN_OK == write(buffer, 2, TEMP_DEVICE_CONTROL_REGISTER)){
            return RETURN_OK;
        }    
    }

    return RETURN_ERROR;
}

ret_t TemperatureDevice::deInit(){
    unsigned char buffer[2];
    if(RETURN_OK == read(buffer, 2, TEMP_DEVICE_CONTROL_REGISTER)){
        buffer[1] &= 0xFB; //dummy bit reset
        if(RETURN_OK == write(buffer, 2, TEMP_DEVICE_CONTROL_REGISTER)){
            return RETURN_OK;
        }    
    }

    return RETURN_ERROR;
}

ret_t TemperatureDevice::read(unsigned char*dptr, unsigned int len, unsigned int addr){
    return receivePhy(dptr, len, addr);
}

ret_t TemperatureDevice::write(unsigned char*dptr, unsigned int len, unsigned int addr){
    return sendPhy(dptr, len, addr);
}

TemperatureDevice::TemperatureDevice()
{
    active = defaultActive;
    id = defaultTemperatureDeviceId;
    powerLevel = defaultPowerLevel;
}

TemperatureDevice::~TemperatureDevice()
{
    deInit();
}