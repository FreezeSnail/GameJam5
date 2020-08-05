#include "exhaust.hpp"
#include "globals.hpp"

static vect_t genVect(){
    int8_t x = rand() % 5 - 10;
    int8_t y = rand() % 10 -5;
    return {x,y};
    
}

Exhaust::Exhaust(Player player){
    genVectors();
    genCounters();

    this->xRoot = &player.xChord + 4;
    this->yRoot = &player.yChord + 4;

}
void Exhaust::genVectors(){
    for(vect_t vec : this->vectors){
        vec = genVect();
    }
}

void Exhaust::genCounters(){
    for(uint8_t count : this->counters){
        count = rand() % 5;
    }
}


void Exhaust::spray(){
    for(uint8_t i = 0; i < 10; i++){
        int8_t x = ((this->counters[i] * this->vectors[i].x)) + *this->xRoot;
        int8_t y = (this->counters[i] * this->vectors[i].y) + *this->yRoot;
        arduboy.drawPixel(x, y);
       // arduboy.drawPixel(*this->xRoot, *this->yRoot);
      
    }
}

void Exhaust::update(){
    arduboy.print(*this->yRoot);
    for(uint8_t count : this->counters){
        count++;

        if(count > 30)
            count = rand() % 5;
 
    }
    spray();
}