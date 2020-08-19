#pragma once
#include "globals.hpp"
#include "collideable.hpp"

class Enemy : public Collideable{
    public:
        uint8_t active = 0;
        virtual void spawn();
        virtual void attack();
        virtual void draw();
        virtual void update();
};