#include "basicEnemy.hpp"
#include "globals.hpp"


void BasicEnemy::spawn(){
    this->active = 1;
    this->xChord = 120;
    this->yChord = 30;
}

void BasicEnemy::despawn(){
    this->active = 0;
}

void BasicEnemy::draw(){
    arduboy.drawBitmap(this->xChord, this->yChord, basicEnemy, 16, 16);
    for(uint8_t i = 0; i < 3; i++){
        if(this->bullet[i].active == 1)
            arduboy.drawCircle(bullet[i].xChord, bullet[i].yChord, 2);
    }
}

void BasicEnemy::updateBullets(){
    this->bullet[0].xChord -= 2;
    this->bullet[0].yChord -= 1;

    this->bullet[1].xChord -= 2;
    this->bullet[1].yChord += 0;

    this->bullet[2].xChord -= 2;
    this->bullet[2].yChord += 1;

    if(this->bullet[0].xChord >200)
        this->bullet[0].active = 0;
    if(this->bullet[1].xChord >200)
        this->bullet[1].active = 0;
    if(this->bullet[2].xChord >200)
        this->bullet[2].active = 0;
}

void BasicEnemy::update(){
    if(active == 0)
        return;
    if(frameCounter % 120 == 0)
        attack();

    draw();
    if(frameCounter % 4 == 0){
        this->xChord -=1;
    }

    if(frameCounter % 2 == 0)
        updateBullets();
    
}

void BasicEnemy::attack(){
    for(uint8_t i = 0; i < 3; i++){
        if(this->bullet[i].active == 0){
            this->bullet[i].active = 1;
            this->bullet[i].spawnBullet(this->xChord, this->yChord+4);
        }
    }

}

Rect BasicEnemy::getHitBox(){
    return Rect(this->xChord+1,this->yChord+2,8,12);
}

void BasicEnemy::collision(Bullets * bullet){
    for(uint8_t i = 0; i < 10; i++){
        if(bullet->bullets[i].active == 1){
            Rect bulletHitBox = Rect(bullet->bullets[i].xChord, bullet->bullets[i].yChord, 2, 2);
            if(arduboy.collide(getHitBox(), bulletHitBox)){
                despawn();
                bullet->bullets[i].despawnBullet();
            }
        }
    }
}


