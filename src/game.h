#ifndef _GAME_H_
#define _GAME_H_

struct GLFWwindow;
class Graphics;

class Game
{
  private:
    GLFWwindow* window;
    Graphics* graphics;
  public:
    Game();
    void run();
};

#endif

