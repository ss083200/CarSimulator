#include "Car.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

Car::Car() : speed(0), direction(0), isRunning(false) {
    shape.setSize(sf::Vector2f(50, 30));
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(sf::Vector2f(25.f, 15.f));
}

void Car::start() {
    isRunning = true;
}

void Car::stop() {
    isRunning = false;
    speed = 0;
}

void Car::accelerate(double amount) {
    if (isRunning) {
        speed = std::min(speed + amount, maxSpeed);
    }
}

void Car::decelerate(double amount) {
    if (isRunning) {
        speed = std::max(speed - amount, 0.0);
    }
}

void Car::turn(double angle) {
    direction += angle;
    direction = std::fmod(direction, 360.0);
    if (direction < 0) direction += 360.0;
    shape.setRotation(static_cast<float>(direction));
}

void Car::applyFriction(double deltaTime) {
    if (isRunning && speed > 0) {
        speed = std::max(speed - friction * deltaTime, 0.0);
    }
}

void Car::update(double deltaTime) {
    applyFriction(deltaTime);
    if (isRunning) {
        float radians = direction * static_cast<float>(M_PI) / 180.0f;
        shape.move(
            static_cast<float>(speed * cos(radians) * deltaTime), 
            static_cast<float>(speed * sin(radians) * deltaTime)
        );
    }
}

void Car::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape& Car::getShape() {
    return shape;
}

double Car::getSpeed() const {
    return speed;
}

double Car::getDirection() const {
    return direction;
}