#ifndef CAR_HPP
#define CAR_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Car {
private:
    double speed;
    double direction;
    bool isRunning;
    sf::RectangleShape shape;
    const double maxSpeed = 100.0;
    const double friction = 0.5;

public:
    Car(); 

    void start();
    void stop();
    void accelerate(double amount);
    void decelerate(double amount);
    void turn(double angle);
    void update(double deltaTime);
    void draw(sf::RenderWindow& window);
    void applyFriction(double deltaTime);

    double getSpeed() const;
    double getDirection() const;
    sf::RectangleShape& getShape();
};

#endif // CAR_HPP
