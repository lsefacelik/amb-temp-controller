#include "gtest/gtest.h"
#include "Heater.h"

const unsigned int dummy = 0x01234567;

TEST(HeaterTests, init) {
    
    Heater tmp;
    EXPECT_EQ(tmp.init(dummy), RETURN_OK);
}

TEST(HeaterTests, connected) {
    
    Heater tmp;
    EXPECT_EQ(tmp.testConnection(), RETURN_OK);
}  