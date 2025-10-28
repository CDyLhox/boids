#include "boid.h"
boid::boid(){
    sf::CircleShape boid(std::rand() % 101);
    boid.setFillColor(sf::Color::Yellow);
    //boid.setPosition(std::rand() % WINDOWWIDTH, std::rand() %windowHeight);
    
    
}
