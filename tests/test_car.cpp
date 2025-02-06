#include <gtest/gtest.h>
#include "Car.hpp"

TEST(CarTest, StartAndStop) {
    Car car;
    car.start();
    EXPECT_TRUE(car.isRunning());
    car.stop();
    EXPECT_FALSE(car.isRunning());
}

TEST(CarTest, SpeedChange) {
    Car car;
    car.start();
    car.accelerate(5.0);
    EXPECT_EQ(car.getSpeed(), 5.0);
    car.decelerate(3.0);
    EXPECT_EQ(car.getSpeed(), 2.0);
}

TEST(CarTest, SpeedNotBelowZero) {
    Car car;
    car.start();
    car.accelerate(2.0);
    car.decelerate(3.0);
    EXPECT_EQ(car.getSpeed(), 0.0);
}

TEST(CarTest, TurningBehavior) {
    Car car;
    car.start();
    car.turn(45);
    EXPECT_EQ(car.getDirection(), 45);
    car.turn(360); // Full rotation
    EXPECT_EQ(car.getDirection(), 45);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
