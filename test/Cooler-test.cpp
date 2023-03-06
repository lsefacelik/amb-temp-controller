#include "gtest/gtest.h"
#include "Cooler.h"

const unsigned int dummy = 0x01234567;

TEST(CoolerTests, init) {
    
    Cooler tmp;
    EXPECT_EQ(tmp.init(dummy), RETURN_OK);
}

TEST(CoolerTests, connected) {
    
    Cooler tmp;
    EXPECT_EQ(tmp.testConnection(), RETURN_OK);
}