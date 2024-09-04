#include "batteryManageSys.h"
#include <gtest/gtest.h>

TEST(BatteryCheckTest, Temperature) {
    EXPECT_TRUE(batteryIsOk(28, 74, 0.6)); // All Parameters in Range
    EXPECT_FALSE(batteryIsOk(48, 83, 0.4)); // Temperature Breach
    EXPECT_FALSE(batteryIsOk(-5, 52, 0.6)); // Temperature Breach
    EXPECT_FALSE(batteryIsOk(30, 10, 0.5)); // Soc Breach
    EXPECT_FALSE(batteryIsOk(25, 60, 0.85)); // Charge rate Breach
    EXPECT_TRUE(batteryIsOk(43, 76, 0.6)); // All Params in Range(Temperature and Soc in warning stage)
    EXPECT_TRUE(batteryIsOk(2, 22, 0.78)); // All Params in Range(Temperature, Soc and ChargeRate in Warning Stage)
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
