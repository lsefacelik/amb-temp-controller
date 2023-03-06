#include "util.h"
#include "conf.h"
#include "cstring"

static unsigned char dummyMemoryPool[MAX_REGISTER_SIZE];

void initMemPool(){
    for(unsigned int i = 0; i < MAX_REGISTER_SIZE; i++){
        dummyMemoryPool[i] = i; 
    }
}

/* Dummy delay function */
void Delay(unsigned int duration_in_ms){
    /* HW specific function related to ticks or simple asm("nop") wrt clock configuration */
}

/* Dummy send operation in Physical Layer */
ret_t sendPhy(unsigned char * data, unsigned int len, unsigned int addr){
    if((data == NULL) || (len == 0) || (&dummyMemoryPool[addr] == NULL))
        return RETURN_ERROR;

    memcpy(&dummyMemoryPool[addr], data, len);
    
    return RETURN_OK;
}

/* Dummy receive operation in Physical Layer */
ret_t receivePhy(unsigned char *data, unsigned int len, unsigned int addr){
    if((data == NULL) || (len == 0) || (&dummyMemoryPool[addr] == NULL))
        return RETURN_ERROR;
        
    memcpy(data, &dummyMemoryPool[addr], len);

    return RETURN_OK;
}