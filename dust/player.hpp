#pragma once
#include "stdint.h"
#include <avr/pgmspace.h>

#include "particles.hpp"

const uint8_t PROGMEM playerSprt[] = {0x20, 0x70, 0x38, 0xa8, 0xe8, 0xd0, 0x90, 0x70, 0xb0, 0x20, 0x60, 0xa8, 0x48, 0xd0, 0xa0, 0xc0, 0x04, 0x0e, 0x1c, 0x15, 0x17, 0x0b, 0x09, 0x0e, 0x0d, 0x04, 0x06, 0x15, 0x12, 0x0b, 0x05, 0x03, };

typedef struct bullets{
    uint8_t xChord;
    uint8_t yChord;
    uint8_t active;
} bullet_t;

class Player {
    private:
        



        

    public:
        uint8_t xChord = 60;
        uint8_t yChord = 40;
        bullet_t bullets[10];
        Particle  particle;

        void draw();
        void update();
        void exhaust(vect_t magnitude);

};