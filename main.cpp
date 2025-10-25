#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <ctime>

std::vector<sf::CircleShape> initialisePositions(int amountOfBoids){
    //initialise boids 
    std::vector<sf::CircleShape> boids;
    boids.reserve(amountOfBoids);

    for(int i =0; i<amountOfBoids; i++){
    sf::CircleShape boid(std::rand()%101);
    boid.setFillColor(sf::Color::Cyan);
    boid.setPosition(std::rand() % 800, std::rand() % 600);
    boids.push_back(boid);

    }

    std::cout << "std::vector<sf::circleshape> initialisePositions " << amountOfBoids << std::endl;
    return boids;
}

sf::CircleShape updatePositions(){
    std::vector<float> v1, v2;
    std::cout << "sf::CircleShape updatePositions" << std::endl;
    
    //return boid;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(800, 600), "Boids");
    auto boids = initialisePositions(7); 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            //THE LOOP
            if (event.type == sf::Event::Closed)
                window.close();
        
        window.clear();
    
        for(auto boid : boids){
        window.draw(boid);
        //updatePositions();
        window.display();
        }
    }
}


