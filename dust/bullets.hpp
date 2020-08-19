#pragma once
#include "globals.hpp"
#include "collideable.hpp"

class Bullet : public Collideable{
    public:
        uint8_t active = 0; // 0 or 1;

};

static Rect getHitbox(Bullet * bullet);

class Bullets{

    public:
        Bullet bullets[10];
        uint8_t * xOrigin;
        uint8_t * yOrigin;


        Bullets(uint8_t * x, uint8_t * y);

        void spawnBullet();
        void despawnBullet(Bullet * bullet);
        void update();
        void draw(Bullet * bullet);

    private:
        Bullet * findInactive();


};