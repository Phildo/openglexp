#ifndef _GAME_H_
#define _GAME_H_

#include "mygl.h"
#include "input.h"
#include "graphics.h"
#include "entity_system.h"

class Game
{
  private:
    MyGL myGL;
    Input input;
    Graphics graphics;

    EntitySystem entitySystem;
  public:
    Game();
    ~Game();
    void run();
};

#endif

