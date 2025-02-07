#include <SFML/Graphics.hpp>
#include <iostream>
#include "Car.hpp"

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

        car.handleInput(window);

        double deltaTime = clock.restart().asSeconds();
        car.update(deltaTime);

        window.clear();
        car.draw(window);
        window.display();
    }

    return 0;
}
