#include <SFML/Graphics.hpp>
#include "Car.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Car Simulator");
    window.setFramerateLimit(60);

    Car myCar;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Get delta time
        float deltaTime = clock.restart().asSeconds();

        // Keyboard input handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            myCar.accelerate(10 * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            myCar.decelerate(10 * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            myCar.turn(-90 * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            myCar.turn(90 * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            myCar.start();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            myCar.stop();
        }

        // Update car position
        myCar.update(deltaTime);

        // Rendering
        window.clear(sf::Color::White);
        myCar.draw(window);
        window.display();
    }

    return 0;
}