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
#include "basicEnemy.hpp"

Particle particle;
Player player;
Exhaust ex(&player);
BasicEnemy em;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.initRandomSeed();
  ex.xRoot = &player.xChord;
  ex.yRoot = &player.yChord;
  ex.genCounters();
  ex.genVectors();
  em.spawn();
   
}


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
  em.update();
  em.collision(&player.bullet);
  //particle.circles(30,30);
  //particle.update();
  frameCounter++;


  
  arduboy.display();
}