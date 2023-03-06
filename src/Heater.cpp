#include "Heater.h"

ret_t Heater::deInit(){
    unsigned char buffer[2];
    if(RETURN_OK == read(buffer, 2, HEATER_CONTROL_REGISTER)){
        buffer[1] &= 0xFB; //dummy bit reset
        if(RETURN_OK == write(buffer, 2, HEATER_CONTROL_REGISTER)){
            return RETURN_OK;
        }    
    }

    return RETURN_ERROR;    
}

ret_t Heater::read(unsigned char *dptr, unsigned int len, unsigned int addr){
    return receivePhy(dptr, len, addr);
}

ret_t Heater::write(unsigned char *dptr, unsigned int len, unsigned int addr){
    return sendPhy(dptr, len, addr);
}

Heater::Heater()
{

}

Heater::~Heater()
{

}