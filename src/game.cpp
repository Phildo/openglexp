#include "game.h"

#include <GLFW/glfw3.h>
#include "graphics.h"

Game::Game()
{
  window = glfwCreateWindow(640,480,"hello world",NULL,NULL);
  graphics = new Graphics(window);
}

void Game::run()
{
  //glfwSetKeyCallback(window, keyPress);
  int i = 0;
  while(!glfwWindowShouldClose(window))
  {
    if(i > 50000)
    {
      i = 0;
      graphics->render();
    }
    i++;
    //glfwPollEvents();
  }
}

