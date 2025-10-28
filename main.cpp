#include "boid.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define WINDOWWIDTH 1080
#define WINDOWHEIGHT 1920

std::vector<sf::CircleShape> initialisePositions(int amountOfBoids)
{
    // initialise boids
    std::vector<sf::CircleShape> boids;
    boids.reserve(amountOfBoids);

    for (int i = 0; i < amountOfBoids; i++) {
        sf::CircleShape boid(std::rand() % 10);
        boid.setFillColor(sf::Color::Cyan);
        boid.setPosition(std::rand() % WINDOWWIDTH, std::rand() % WINDOWHEIGHT);
        boids.push_back(boid);
    }

    std::cout << "std::vector<sf::circleshape> initialisePositions " << amountOfBoids << std::endl;
    return boids;
}

sf::Vector2f rule1(std::vector<sf::CircleShape>& boids, int index)
{
    sf::Vector2f perceivedCentre(0.0f, 0.0f);

    for (int i = 0; i < boids.size(); i++) {
        if (i != index) {
            perceivedCentre += boids[i].getPosition();
        }
    }

    perceivedCentre /= static_cast<float>(boids.size() - 1);
    std::cout << "rule1 perceivedCentre" << std::endl;
    return perceivedCentre - boids[index].getPosition();
}

sf::Vector2f rule2(std::vector<sf::CircleShape>& boids, int index)
{
    sf::Vector2f displacement;

    for (int i = 0; i < boids.size(); i++) {
        if (i != index) {
            sf::Vector2f diff = boids[index].getPosition() - boids[i].getPosition();
            float distance = std::sqrt(diff.x * diff.x + diff.y * diff.y);

            if (distance < 100.0f) {
                displacement -= diff;
            }
        }
    }

    std::cout << "rule2, distance" << std::endl;
    return displacement;
}
sf::Vector2f rule3(std::vector<sf::CircleShape>& boids, int index)
{
    sf::Vector2f perceivedVelocity;

    /*for(int i = 0; i < boids.size(); i++){
        if (i != index) {
            perceivedVelocity += boids[i] + 1;// PLUS VELOCITY
        }
    }

    perceivedVelocity /= boids.size()-1;*/

    std::cout << "rule3 perceived velocity" << std::endl;
    return perceivedVelocity;
}

void updatePositions(std::vector<sf::CircleShape>& boids)
{
    sf::Vector2f v1 = rule1(boids, 0);
    sf::Vector2f v2 = rule2(boids, 0);
    sf::Vector2f v3 = rule3(boids, 0);

    std::cout << "sf::CircleShape updatePositions\n";
    std::cout << "v1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "v2: (" << v2.x << ", " << v2.y << ")\n";
    std::cout << "v3: (" << v3.x << ", " << v3.y << ")\n";

    for (auto& boid : boids) {
        boid.setPosition(
            fmod(boid.getPosition().x + v1.x + WINDOWWIDTH, WINDOWWIDTH),
            fmod(boid.getPosition().y + v1.y + WINDOWHEIGHT, WINDOWHEIGHT));
    }
}

int main()
{

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Boids");

    auto boids = initialisePositions(70);

    // teken alleen een update wanneer nodig
    while (window.isOpen()) {
        // window.setMouseCursorVisible(false);

        sf::Event event;
        while (window.pollEvent(event))
            // THE LOOP
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color(0, 0, 0, 1)); // Window.clear is de background functie

        updatePositions(boids);
        for (auto& boid : boids) {
            window.draw(boid);
        }

        window.display();
    }
}
