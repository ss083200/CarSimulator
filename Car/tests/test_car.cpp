#include <gtest/gtest.h>
#include "Car.hpp"

class CarTest : public ::testing::Test {
protected:
    Car car;
};

// Test car initialization
TEST_F(CarTest, Initialization) {
    EXPECT_DOUBLE_EQ(car.getSpeed(), 0.0);
    EXPECT_DOUBLE_EQ(car.getDirection(), 0.0);
}

// Test starting and stopping the car
TEST_F(CarTest, StartStopTest) {
    car.start();
    car.accelerate(10);
    EXPECT_GT(car.getSpeed(), 0);

    car.stop();
    EXPECT_DOUBLE_EQ(car.getSpeed(), 0.0);
}

// Test acceleration
TEST_F(CarTest, AccelerationTest) {
    car.start();
    car.accelerate(20);
    EXPECT_DOUBLE_EQ(car.getSpeed(), 20.0);
}

// Test deceleration
TEST_F(CarTest, DecelerationTest) {
    car.start();
    car.accelerate(50);
    car.decelerate(20);
    EXPECT_DOUBLE_EQ(car.getSpeed(), 30.0);
}

// Test speed cannot go below zero
TEST_F(CarTest, SpeedLimitTest) {
    car.start();
    car.accelerate(10);
    car.decelerate(15);
    EXPECT_DOUBLE_EQ(car.getSpeed(), 0.0);
}

// Test turning and angle wrapping
TEST_F(CarTest, TurningTest) {
    car.turn(370);
    EXPECT_DOUBLE_EQ(car.getDirection(), 10.0);

    car.turn(-380);
    EXPECT_DOUBLE_EQ(car.getDirection(), 630.0 - 380.0);
}

// Test maximum speed limit
TEST_F(CarTest, MaxSpeedTest) {
    car.start();
    car.accelerate(150);
    EXPECT_LE(car.getSpeed(), 100.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}