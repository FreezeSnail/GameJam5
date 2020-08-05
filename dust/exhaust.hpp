#pragma once
#include "particles.hpp"
#include "player.hpp"

class Exhaust : Particle{
    public:
        vect_t vectors[10];
        uint8_t counters[10];

        uint8_t * xRoot;
        uint8_t * yRoot;

        Exhaust(Player player);

        void genVectors();
        void genCounters();
        void spray();
        void update();
};