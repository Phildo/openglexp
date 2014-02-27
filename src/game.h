#ifndef _GAME_H_
#define _GAME_H_

class MyGL;
class Input;
class Graphics;
class EntitySystem;

class Game
{
  private:
    MyGL *myGL;
    Input *input;
    Graphics *graphics;

    EntitySystem *entitySystem;
  public:
    Game();
    ~Game();
    void run();
};

#endif

