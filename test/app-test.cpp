#include "gtest/gtest.h"
#include "app.h"

TEST(AppTests, init){
    
    ret_t status = RETURN_OK;
    TemperatureSensor tempSensor;
    Cooler coolerDev;
    Heater heaterDev;

    appInit(status, tempSensor, coolerDev, heaterDev);

    EXPECT_EQ(status, RETURN_OK);
}

TEST(AppTests, connection){

    ret_t status = RETURN_OK;
    TemperatureSensor tempSensor;
    Cooler coolerDev;
    Heater heaterDev;

    appTest(status, tempSensor, coolerDev, heaterDev);

    EXPECT_EQ(status, RETURN_OK);    
}