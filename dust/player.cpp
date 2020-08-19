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

Player::Player(){
    this->xChord = 40;
    this->yChord = 40;
}


void Player::draw(){
    arduboy.drawBitmap(this->xChord, this->yChord, playerSprt, 16, 16);
    //exhaust({1,2});

}

void Player::update(){
    this->particle.update();
    draw();

    if(arduboy.pressed(UP_BUTTON)){
        yChord--;
    }
    else if (arduboy.pressed(DOWN_BUTTON)){
        yChord++;
    }
    else if (arduboy.pressed(LEFT_BUTTON)){
        xChord--;
    }
    else if (arduboy.pressed(RIGHT_BUTTON)){
        xChord++;
    }

    if(arduboy.justPressed(A_BUTTON))
        bullet.spawnBullet();
    bullet.update();
}

void Player::collide(Bullets emBullets[20], Enemy enemys[]){
    Rect playerRect = Rect(this->xChord+1, this->yChord+1, 14, 8);
    
    
}