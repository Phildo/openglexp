#ifndef _GAME_H_
#define _GAME_H_

struct GLFWwindow;
class Input;
class Graphics;

class Game
{
  private:
    GLFWwindow* window;
    Input* input;
    Graphics* graphics;
  public:
    Game();
    ~Game();
    void run();
};

#endif

