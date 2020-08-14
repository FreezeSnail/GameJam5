#pragma once
#include "globals.hpp"

typedef struct bullets{
    uint8_t xChord;
    uint8_t yChord;
    uint8_t active = 0; // 0 or 1;
} bullet_t;

class Bullet{

    public:
        bullet_t bullets[10];
        uint8_t * xOrigin;
        uint8_t * yOrigin;

        Bullet(uint8_t * x, uint8_t * y);

        void spawnBullet();
        void despawnBullet(bullet_t * bullet);
        void update();
        void draw(bullet_t * bullet);

    private:
        bullet_t * findInactive();


};