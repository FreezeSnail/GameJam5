#pragma once
#include "globals.hpp"

class Collideable{
    public:
        uint8_t xChord;
        uint8_t yChord;

        virtual Rect getHitBox();
        virtual void update();
        virtual void draw();

};