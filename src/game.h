#ifndef _GAME_H_
#define _GAME_H_

class MyGL;
class Input;
class Graphics;
class World;
class WorldRenderer;

class Game
{
  private:
    MyGL* myGL;
    Input* input;
    Graphics* graphics;
    World* world;
    WorldRenderer* worldRenderer;
  public:
    Game();
    ~Game();
    void run();
};

#endif

