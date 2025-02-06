#include <gtest/gtest.h>
#include "Car.hpp"

TEST(CarTest, InitialPosition) {
    Car car;
    car.start();
    EXPECT_EQ(car.getShape().getPosition().x, 400); // Center position
    EXPECT_EQ(car.getShape().getPosition().y, 300); // Center position
}

TEST(CarTest, Accelerate) {
    Car car;
    car.start();
    car.accelerate(1.0);
    car.update(1.0);
    EXPECT_GT(car.getShape().getPosition().y, 300); // Assuming initial y position is 300
}

TEST(CarTest, Stop) {
    Car car;
    car.start();
    car.accelerate(1.0);
    car.update(1.0);
    car.stop();
    float positionY = car.getShape().getPosition().y;
    car.update(1.0);
    EXPECT_EQ(car.getShape().getPosition().y, positionY);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}