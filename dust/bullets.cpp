#include "bullets.hpp"
#include "globals.hpp"

Bullets::Bullets(uint8_t * x, uint8_t * y){
    this->xOrigin = x;
    this->yOrigin = y;
    
}

Bullet * Bullets::findInactive(){
    for(uint8_t i = 0; i < 10; i++){
        if(bullets[i].active == 0)
            return &bullets[i];
    }

    return nullptr;
}

void Bullets::spawnBullet(){
    Bullet * active = findInactive();
    if(active == nullptr){
        return;
    }

    active->xChord = *this->xOrigin + 16;
    active->yChord = *this->yOrigin + 8;
    active->active = 1;
}

void Bullets::despawnBullet(Bullet * bullet){
    bullet->active = 0;
}

void Bullets::draw(Bullet * bullet){
            arduboy.drawCircle(bullet->xChord, bullet->yChord, 2);
            arduboy.drawCircle(bullet->xChord+2, bullet->yChord, 2);
}

void Bullets::update(){
    for(int i = 0; i < 10; i++){
        if(bullets[i].active){
            draw(&bullets[i]);
            bullets[i].xChord += 2;
            if(bullets[i].xChord > 180)
                despawnBullet(&bullets[i]);
        }
    }
}

static Rect getHitbox(Bullet * bullet){
    return Rect(bullet->xChord, bullet->yChord, 4,2); 

}