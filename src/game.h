#ifndef _GAME_H_
#define _GAME_H_

class MyGL;
class Input;
class Graphics;
class EntitySystem;
class Scener;

class Game
{
  private:
    MyGL* myGL;
    Input* input;
    Graphics* graphics;

    EntitySystem* entitySystem;
    Scener* scener;
  public:
    Game();
    ~Game();
    void run();
};

#endif

