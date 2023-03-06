#include "Cooler.h"

ret_t Cooler::deInit(){
    unsigned char buffer[2];
    if(RETURN_OK == read(buffer, 2, COOLER_CONTROL_REGISTER)){
        buffer[1] &= 0xFB; //dummy bit reset
        if(RETURN_OK == write(buffer, 2, COOLER_CONTROL_REGISTER)){
            return RETURN_OK;
        }    
    }

    return RETURN_ERROR;    
}

ret_t Cooler::read(unsigned char *dptr, unsigned int len, unsigned int addr){
    return receivePhy(dptr, len, addr);
}

ret_t Cooler::write(unsigned char *dptr, unsigned int len, unsigned int addr){
    return sendPhy(dptr, len, addr);
}

Cooler::Cooler()
{

}

Cooler::~Cooler()
{

}