#include "bullets.hpp"
#include "globals.hpp"

Bullet::Bullet(uint8_t * x, uint8_t * y){
    this->xOrigin = x;
    this->yOrigin = y;
}

bullet_t * Bullet::findInactive(){
    for(uint8_t i = 0; i < 10; i++){
        if(bullets[i].active == 0)
            return &bullets[i];
    }

    return nullptr;
}

void Bullet::spawnBullet(){
    bullet_t * active = findInactive();
    if(active == nullptr){
        return;
    }

    active->xChord = *this->xOrigin + 16;
    active->yChord = *this->yOrigin + 8;
    active->active = 1;
}

void Bullet::despawnBullet(bullet_t * bullet){
    bullet->active = 0;
}

void Bullet::draw(bullet_t * bullet){
            arduboy.drawCircle(bullet->xChord, bullet->yChord, 2);
            arduboy.drawCircle(bullet->xChord+2, bullet->yChord, 2);
}

void Bullet::update(){
    for(int i = 0; i < 10; i++){
        if(bullets[i].active){
            draw(&bullets[i]);
            bullets[i].xChord += 2;
            if(bullets[i].xChord > 180)
                despawnBullet(&bullets[i]);
        }
    }
}