#include "game.h"

Game::Game() :
  myGL(),
  input(Input(myGL)),
  graphics(Graphics(myGL)),
  entitySystem()
{
}

Game::~Game()
{
}

void Game::run()
{
  bool run = true;
  while(run)
  {
    input.poll();
    run = (!glfwWindowShouldClose(myGL.window) && (glfwGetKey(myGL.window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
  }
}

