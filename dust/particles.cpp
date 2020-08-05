#include "particles.hpp"

#include "globals.hpp"

static int counter(uint8_t i){
    i++;
    if(i > 30)
        return 60 -i;
    if (i > 60)
        return 0;
    if(i < 1)
        return 0;

    return i;
}
void Particle::update(){
    this->particleClock++;
    if(this->particleClock > 60)
        this->particleClock = 0;
}
void Particle::circles(uint8_t x, uint8_t y){
        uint8_t r = counter(this->particleClock);
        arduboy.drawCircle(x,y,r);
}

void Particle::spray(uint8_t x, uint8_t y, vect_t magnitude){
        uint8_t r = this->particleClock;
        arduboy.drawPixel(x+(r*magnitude.x), y+(r * magnitude.y));
}
