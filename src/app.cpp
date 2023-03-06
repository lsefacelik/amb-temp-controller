#include <iostream>
#include "app.h"

using namespace std;

void appInit(ret_t &status, TemperatureSensor &tempSensor, Cooler &coolerDev, Heater &heaterDev){    
    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel, DefaultLowTempLevel)){
        status = RETURN_ERROR;
        cout << "TempSensor init error." << endl;        
    }

    if(RETURN_OK != coolerDev.init(DefaultCoolerPowerLevel)){
        status = RETURN_ERROR;
        cout << "coolerDev init error." << endl;
    }

    if(RETURN_OK != heaterDev.init(DefaultHeaterPowerLevel)){
        status = RETURN_ERROR;
        cout << "heaterDev init error." << endl;
    }
}

void appTest(ret_t &status, TemperatureSensor &tempSensor, Cooler &coolerDev, Heater &heaterDev){
    
    if(RETURN_OK != tempSensor.testConnection()){
        status = RETURN_ERROR;
        cout << "TempSensor test error." << endl;
    }

    if(RETURN_OK != coolerDev.testConnection()){
        status = RETURN_ERROR;
        cout << "coolerDev test error." << endl;
    }

    if(RETURN_OK != heaterDev.testConnection()){
        status = RETURN_ERROR;
        cout << "heaterDev test error." << endl;
    }
}

ret_t appMain(statusAmbTempController_t &appState, alarm_t &alarmStatus, unsigned char &alarmCount, TemperatureSensor &tempSensor, Cooler &coolerDev, Heater &heaterDev){
    switch(appState){
        case NORMAL_OP:
            alarmStatus = tempSensor.getAlarmStatus();
            if(alarmStatus != ALARM_ERROR)
                alarmCount = 0;

            switch(alarmStatus){
                case NO_ALARM:                        
                    break;
                case ALARM_HIGH:                        
                    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel - DefaultHighTempSensitivity, DefaultLowTempLevel)){                            
                        cout << "TempSensor init error at" << appState << alarmStatus << endl;          
                    }
                    else{
                        coolerDev.run();
                        appState = HIGH_LIMIT_OP;
                    }                        
                    break;
                case ALARM_LOW:
                    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel, DefaultLowTempLevel + DefaultLowTempSensitivity)){                            
                        cout << "TempSensor init error at" << appState << alarmStatus << endl;        
                    }
                    else{
                        heaterDev.run();
                        appState = LOW_LIMIT_OP;
                    }
                    break;
                case ALARM_ERROR:
                    alarmCount++;
                    if(alarmCount > MAX_CONSECUTIVE_ALARM_COUNT){
                        cout << "Comm error at" << appState << alarmStatus << endl;   
                        return RETURN_ERROR;
                    }                        
                    break;            
                default:
                    cout << "Undefined state error at" << appState << alarmStatus << endl;   
                    return RETURN_ERROR;
                    break;
            }
            
            break;
        case LOW_LIMIT_OP:
            alarmStatus = tempSensor.getAlarmStatus();
            if(alarmStatus != ALARM_ERROR)
                alarmCount = 0;
            
            switch(alarmStatus){
                case NO_ALARM:
                    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel, DefaultLowTempLevel)){                            
                        cout << "TempSensor init error at" << appState << alarmStatus << endl;         
                    }
                    else{
                        heaterDev.stop();
                        appState = NORMAL_OP;
                    }
                    break;
                case ALARM_HIGH:
                    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel - DefaultHighTempSensitivity, DefaultLowTempLevel)){                            
                        cout << "TempSensor init error at" << appState << alarmStatus << endl;          
                    }
                    else{
                        heaterDev.stop();
                        coolerDev.run();
                        appState = HIGH_LIMIT_OP;
                    }      
                    break;
                case ALARM_LOW:
                    break;
                case ALARM_ERROR:
                    alarmCount++;
                    if(alarmCount > MAX_CONSECUTIVE_ALARM_COUNT){
                        cout << "Comm error at" << appState << alarmStatus << endl;
                        return RETURN_ERROR;
                    }                        
                    break;            
                default:
                    cout << "Undefined state error at" << appState << alarmStatus << endl;
                    return RETURN_ERROR;
                    break;
            }

            break;
        case HIGH_LIMIT_OP:
            alarmStatus = tempSensor.getAlarmStatus();
            if(alarmStatus != ALARM_ERROR)
                alarmCount = 0;
            
            switch(alarmStatus){
                case NO_ALARM:    
                    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel, DefaultLowTempLevel)){                            
                        cout << "TempSensor init error at" << appState << alarmStatus << endl;         
                    }
                    else{
                        coolerDev.stop();
                        appState = NORMAL_OP;
                    }                    
                    break;
                case ALARM_HIGH:
                    break;
                case ALARM_LOW:
                    if(RETURN_OK != tempSensor.init(DefaultTempReadPeriod, DefaultHighTempLevel, DefaultLowTempLevel + DefaultLowTempSensitivity)){                            
                        cout << "TempSensor init error at" << appState << alarmStatus << endl;        
                    }
                    else{
                        coolerDev.stop();
                        heaterDev.run();
                        appState = LOW_LIMIT_OP;
                    }
                    break;
                case ALARM_ERROR:
                    alarmCount++;
                    if(alarmCount > MAX_CONSECUTIVE_ALARM_COUNT){
                        cout << "Comm error at" << appState << alarmStatus << endl;
                        return RETURN_ERROR;
                    }                        
                    break;            
                default:
                    cout << "Undefined state error at" << appState << alarmStatus << endl;
                    return RETURN_ERROR;
                    break;
            }            
        break;
        case STANDBY:
        break;
        case DEFAULT:
        case INIT:
            cout << "Wrong app state error." << endl;
            return RETURN_ERROR;
            break;

        default:
            cout << "Undefined app state error" << appState << endl;
            return RETURN_ERROR;
            break;
    }
    return RETURN_OK;
}