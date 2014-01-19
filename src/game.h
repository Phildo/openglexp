#ifndef _GAME_H_
#define _GAME_H_

#include "mygl.h"
#include "input.h"
#include "graphics.h"

class Game
{
  private:
    MyGL myGL;
    Input input;
    Graphics graphics;
  public:
    Game():
      myGL{MyGL()},
      input{Input(myGL)},
      graphics{Graphics(myGL)},
      {};
    ~Game();
    void run();
};

#endif

