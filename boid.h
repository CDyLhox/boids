#include <cstdlib>
#include <SFML/Graphics.hpp>

class boid{
    boid();
    ~boid();
    
    public:
    void setVelocity();
    float getVelocity();
    void setPosition();
    void getPosition(); 
    protected:

    private:
    float velocity = 0;
};
