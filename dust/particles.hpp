#pragma once
#include "stdint.h"

typedef struct vect{
    int8_t x;
    int8_t y;
} vect_t;

class Particle{
    
    public:
        uint8_t particleClock = 0;
        void update();
        void circles(uint8_t x, uint8_t y);
        void spray(uint8_t x, uint8_t y, vect_t magnitude);
};