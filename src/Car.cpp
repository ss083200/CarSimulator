/*
 * File: Car.cpp
 * Author: Your Name
 * Description: This file contains the implementation of the Car class,
 *              which simulates a car's behavior in a driving simulation.
 *              It includes methods for start, stop, acceleration, deceleration, 
 *              turning etc.
 */

#include "Car.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

// Constructor for initialization
Car::Car() : speed(0), direction(0), isRunning(false) {
    shape.setSize(sf::Vector2f(50, 30));
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(sf::Vector2f(25.f, 15.f));
    shape.setPosition(400, 300); // Set initial position to center
}

// Starts the car's engine
void Car::start() {
    isRunning = true;
}

// Stops the car's engine
void Car::stop() {
    isRunning = false;
    speed = 0;
}

// Accelerates the car by a specified amount
void Car::accelerate(double amount) {
    if (isRunning) {
        // Adjust acceleration based on current speed
        double accelerationFactor = (maxSpeed - speed) / maxSpeed; // Factor decreases as speed increases
        speed = std::min(speed + amount * accelerationFactor, maxSpeed);
    }
}

// Decelerates the car by a specified amount
void Car::decelerate(double amount) {
    if (isRunning) {
        speed = std::max(speed - amount, 0.0);
    }
}

// Turns the car by a specified angle
void Car::turn(double angle) {
    // Adjust turning based on current speed
    double turnFactor = (maxSpeed - speed) / maxSpeed; // Factor decreases as speed increases
    direction += angle * turnFactor;
    if (direction >= 360) direction -= 360;
    if (direction < 0) direction += 360;
    shape.setRotation(static_cast<float>(direction));
}

 // Applies friction to the car's speed to simulate deceleration over time
void Car::applyFriction(double deltaTime) {
    if (isRunning && speed > 0) {
        speed = std::max(speed - friction * deltaTime, 0.0);
    }
}

// Updates the car's state based on the elapsed time
void Car::update(double deltaTime) {
    // Apply friction to the car's speed to simulate deceleration
    applyFriction(deltaTime);

    // Check if the car is running before updating its position
    if (isRunning) {
        // Convert the direction from degrees to radians for trigonometric functions
        float radians = direction * (M_PI / 180.0f);

        // Move the car based on its speed and direction
        shape.move(
            static_cast<float>(speed * cos(radians) * deltaTime), 
            static_cast<float>(speed * sin(radians) * deltaTime)
        );

        // Boundary checks to ensure the car stays within the window limits
        sf::Vector2f position = shape.getPosition();
        if (position.x < 0) position.x = 0; // Prevent moving left out of bounds
        else if (position.x > 800) position.x = 800; // Prevent moving right out of bounds
        if (position.y < 0) position.y = 0; // Prevent moving above the top
        else if (position.y > 600) position.y = 600; // Prevent moving below the bottom

        shape.setPosition(position);
    }
}

// Draws the car on the specified render window
void Car::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Returns a reference to the car's shape for rendering
sf::RectangleShape& Car::getShape() {
    return shape;
}

// Returns the current speed of the car
double Car::getSpeed() const {
    return speed;
}

// Returns the current direction of the car
double Car::getDirection() const {
    return direction;
}

// Checks if the car is running
bool Car::getIsRunning() const {
    return isRunning;
}

// Handles user inputs from keyboard presses to control the car's behavior
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
