#include "player.hpp"
#include "globals.hpp"

void Player::exhaust(vect_t magnitude){
        uint8_t r = this->particle.particleClock;
        for(int i = 0; i < 10; i++){
            int8_t mod = (rand() % 10) -5;
            if(r < 15)
                arduboy.drawPixel(this->xChord+3+(r*-1), this->yChord+4+(r * mod));
        }
        
}
void Player::draw(){
    arduboy.drawBitmap(this->xChord, this->yChord, playerSprt, 16, 16);
    //exhaust({1,2});

}

void Player::update(){
    this->particle.update();
    draw();
}