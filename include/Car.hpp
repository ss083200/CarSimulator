#ifndef CAR_HPP
#define CAR_HPP

#include <SFML/Graphics.hpp>

class Car {
public:
    // Constructor to initialize the car's state
    Car();

    // Starts the car's engine
    void start();

    // Stops the car's engine
    void stop();

    // Accelerates the car by a specified amount
    // The acceleration is slower at higher speeds
    void accelerate(double amount);

    // Decelerates the car by a specified amount
    void decelerate(double amount);

    // Turns the car by a specified angle
    // The turning is slower at higher speeds
    void turn(double angle);

    // Applies friction to the car's speed over a given time interval
    void applyFriction(double deltaTime);

    // Updates the car's state based on the elapsed time
    void update(double deltaTime);

    // Draws the car on the specified render window
    void draw(sf::RenderWindow& window);

    // Returns a reference to the car's shape for rendering
    sf::RectangleShape& getShape();

    double getSpeed() const;

    // Returns the current direction of the car
    double getDirection() const;
    bool getIsRunning() const;

    // Handles user input for controlling the car
    void handleInput(sf::RenderWindow& window);

private:
    double speed;
    double direction;
    bool isRunning;
    sf::RectangleShape shape; // shape of the Car
    static constexpr double maxSpeed = 200.0; // Max speed in km/h
    static constexpr double friction = 5.0;  // Friction coefficient
};

#endif
