#ifndef _GAME_H_
#define _GAME_H_

class MyGL;
class Input;
class EntitySystem;
class Scener;

class Game
{
  private:
    MyGL* myGL;
    Input* input;

    EntitySystem* entitySystem;
    Scener* scener;
  public:
    Game();
    ~Game();
    void run();
};

#endif

