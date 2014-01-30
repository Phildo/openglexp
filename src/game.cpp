#include "game.h"

Game::Game():myGL(),input(Input(myGL)),graphics(Graphics(myGL)),entitySystem()
{
}

Game::~Game()
{
}

void Game::run()
{
  int i = 0;
  bool run = true;
  while(run)
  {
    input.poll();
    if(i > 5)
    {
      i = 0;
      graphics.render();
    }
    run = (!glfwWindowShouldClose(myGL.window) && (glfwGetKey(myGL.window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
    i++;
  }
}

