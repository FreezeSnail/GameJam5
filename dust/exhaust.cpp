#include "exhaust.hpp"
#include "globals.hpp"

static vect_t genVect(){
    int8_t x = rand() % 5 - 10;
    int8_t y = rand() % 10 -5;
    return {x,y};
    
}

Exhaust::Exhaust(Player *player){
    genVectors();
    genCounters();

    this->xRoot = &player->xChord;
    this->yRoot = &player->yChord;

}
void Exhaust::genVectors(){
    for(uint8_t i = 0; i < 10; i++){
        this->vectors[i] = genVect();
    }
}

void Exhaust::genCounters(){
    for(uint8_t i = 0; i < 10; i++){
        this->counters[i] = rand() % 5;
    }
}


void Exhaust::spray(){
    for(uint8_t i = 0; i < 10; i++){
        int8_t x = ((this->counters[i] * this->vectors[i].x)) + *this->xRoot+5;
        int8_t y = (this->counters[i] * this->vectors[i].y) + *this->yRoot+8;
        if(rand() % i == 0)
            arduboy.drawCircle(x,y, (rand() %3));
        else
            arduboy.drawPixel(x, y);
       // arduboy.drawPixel(*this->xRoot, *this->yRoot);
      
    }
}

void Exhaust::update(){
    for(uint8_t i = 0; i < 10; i++){
        this->counters[i] +=1;
        

        if(this->counters[i] > 3)
            this->counters[i] = rand() % 3;
 
    }
    spray();
}