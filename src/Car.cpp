#include "Car.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

Car::Car() : speed(0), direction(0), isRunning(false) {
    shape.setSize(sf::Vector2f(50, 30));
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(sf::Vector2f(25.f, 15.f));
    shape.setPosition(400, 300); // Set initial position to center
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
    if (direction >= 360) direction -= 360;
    if (direction < 0) direction += 360;
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
        float radians = direction * (M_PI / 180.0f);
        shape.move(
            static_cast<float>(speed * cos(radians) * deltaTime), 
            static_cast<float>(speed * sin(radians) * deltaTime)
        );

        // Boundary checks
        sf::Vector2f position = shape.getPosition();
        if (position.x < 0) position.x = 0;
        else if (position.x > 800) position.x = 800;
        if (position.y < 0) position.y = 0;
        else if (position.y > 600) position.y = 600;
        shape.setPosition(position);
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

bool Car::getIsRunning() const {
    return isRunning;
}

void Car::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        accelerate(1.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        decelerate(1.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        turn(-2.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        turn(2.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        stop();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        start();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window.close();
    }
}
