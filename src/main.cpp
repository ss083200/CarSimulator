#include <SFML/Graphics.hpp>
#include <iostream>
#include "Car.hpp"

void handleInput(Car& car, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        car.accelerate(1.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        car.decelerate(1.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        car.turn(-2.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        car.turn(2.0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        car.stop();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        car.start();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window.close();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Car Simulator");
    Car car;
    car.getShape().setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput(car, window);

        double deltaTime = clock.restart().asSeconds();
        car.update(deltaTime);

        window.clear();
        car.draw(window);
        window.display();
    }

    return 0;
}
