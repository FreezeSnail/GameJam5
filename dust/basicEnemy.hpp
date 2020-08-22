#pragma once
#include "enemy.hpp"
#include "bullets.hpp"
#include "globals.hpp"
#include "player.hpp"

const uint8_t PROGMEM basicEnemy[] = {0x00, 0xb8, 0x94, 0x6c, 0x58, 0xf4, 0xc4, 0x80, 0xc0, 0xa0, 0x80, 0xc0, 0xa0, 0xc0, 0xa0, 0x00, 0x00, 0x1d, 0x29, 0x36, 0x1a, 0x2f, 0x23, 0x01, 0x03, 0x05, 0x01, 0x03, 0x05, 0x03, 0x05, 0x00, };


class BasicEnemy : public Enemy{
    public:

        Bullet bullet[3];
        void spawn();
        void despawn();
        void attack();
        void draw();
        void update();
        Rect getHitBox();
        Rect bulletBox(uint8_t x, uint8_t y);
        void collision(Bullets * bullets);
        uint8_t bulletHitCheck();

    private:
        void updateBullets();
};