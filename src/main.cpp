#include <SFML/Graphics.hpp>
#include <iostream>
#include "Car.hpp"

int main() {
    // Create a window for the simulation
    sf::RenderWindow window(sf::VideoMode(800, 600), "Car Simulator");
    Car car;
    car.getShape().setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::Clock clock; // Clock to track elapsed time
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close the window on close event
        }

        car.handleInput(window); // Handle user input for car control

        double deltaTime = clock.restart().asSeconds(); // Calculate time since last frame
        car.update(deltaTime); // Update the car's state

        window.clear(); // Clear the window for the next frame
        car.draw(window); // Draw the car on the window
        window.display(); // Display the updated window contents
    }

    return 0;
}
