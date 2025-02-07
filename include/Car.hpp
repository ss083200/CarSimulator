#ifndef CAR_HPP
#define CAR_HPP

#include <SFML/Graphics.hpp>

class Car {
public:
    Car();
    void start();
    void stop();
    void accelerate(double amount);
    void decelerate(double amount);
    void turn(double angle);
    void applyFriction(double deltaTime);
    void update(double deltaTime);
    void draw(sf::RenderWindow& window);
    sf::RectangleShape& getShape();
    double getSpeed() const;
    double getDirection() const;
    bool getIsRunning() const;
    void handleInput(sf::RenderWindow& window);

private:
    double speed;
    double direction;
    bool isRunning;
    sf::RectangleShape shape;
    static constexpr double maxSpeed = 200.0; // Max speed in km/h
    static constexpr double friction = 5.0;  // Friction coefficient
};

#endif
