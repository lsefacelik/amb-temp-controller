#include "gtest/gtest.h"
#include "TemperatureSensor.h"

const unsigned int dummy = 0x01234567;

TEST(TemperatureSensorTests, init) {
    
    TemperatureSensor tmp;
    EXPECT_EQ(tmp.init(dummy, dummy, dummy), RETURN_OK);
}

TEST(TemperatureSensorTests, connected) {
    
    TemperatureSensor tmp;
    EXPECT_EQ(tmp.testConnection(), RETURN_OK);
}

TEST(TemperatureSensorTests, convert_celcius) {
    
    constexpr unsigned char predeterminedVal = 0x34;

    TemperatureSensor tmp;
    
    EXPECT_EQ(predeterminedVal, tmp.convertCelcius(16.04f));
}
