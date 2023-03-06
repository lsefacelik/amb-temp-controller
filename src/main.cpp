#include <iostream>
#include "app.h"

using namespace std;



statusAmbTempController_t appState = DEFAULT;

int main(){
    ret_t status = RETURN_OK;
    alarm_t alarmStatus;
    unsigned char alarmCount = 0;
    TemperatureSensor tempSensor;
    Cooler coolerDev;
    Heater heaterDev;

    /* Init */
    appState = INIT;    
    appInit(status, tempSensor, coolerDev, heaterDev);
    cout << "Init is done." << endl;
    
    /* Actions wrt init results */
    if(RETURN_ERROR == status){
        return 1;
    }
    
    cout << "Init is successful." << endl;

    /* Testing after init */
    appTest(status, tempSensor, coolerDev, heaterDev);

    cout << "Test is done." << endl;

    /* Actions wrt test results */
    if(RETURN_ERROR == status){
        return 1;
    }

    cout << "Test is successful." << endl;
    
    /* Super-loop */
    while(1){
        
        status = appMain(appState, alarmStatus, alarmCount, tempSensor, coolerDev, heaterDev);
        if(status == RETURN_ERROR){
            return 1;
        }

        Delay(ApplicationPeriod);
    }

    return 0;
}