/* Game Jam 5
 * Dust
 * 
 * @FreezingSnail
 * 
 * 
 */
#include <stdint.h>

#include "particles.hpp"
#include "player.hpp"
#include "globals.hpp"
#include "exhaust.hpp"


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.initRandomSeed();
   
}

Particle particle;
Player player;
Exhaust ex = Exhaust(player);

//Main loop
void loop() {
  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();

  player.draw();
  player.update();

  ex.update();
  //particle.circles(30,30);
  //particle.update();


  
  arduboy.display();
}