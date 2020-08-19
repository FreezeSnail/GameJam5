#pragma once
#include "globals.hpp"

class Collideable{
    public:
        uint8_t xChord;
        uint8_t yChord;

        Rect getRect();

};