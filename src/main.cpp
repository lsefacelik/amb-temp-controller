#include <iostream>
#include "TemperatureSensor.h"

constexpr unsigned int InitialTempPeriod = 235;

using namespace std;

int main(){

    TemperatureSensor ambTempSensor(InitialTempPeriod);
    float tmpData;
    ambTempSensor.getData(tmpData); 
    cout << "Init successful. Temperature sensor data: " << tmpData << endl;

    return 0;
}