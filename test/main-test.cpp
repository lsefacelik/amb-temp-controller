#include "gtest/gtest.h"
#include "util.h"

int main(int argc, char **argv) {
    
    /* Avoid reading all zeros */
    initMemPool();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}