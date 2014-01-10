#include "game.h"
#include "gl_include.h"
#include "mygl.h"
#include "input.h"
#include "graphics.h"
#include "world.h"
#include "world_renderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Game::Game()
{
  myGL = new MyGL();
  input = new Input(myGL->window);
  graphics = new Graphics(myGL->window);
  world = new World();
  worldRenderer = new WorldRenderer();
}

void Game::run()
{
  int i = 0;
  while(!glfwWindowShouldClose(myGL->window) && (glfwGetKey(myGL->window, GLFW_KEY_ESCAPE) != GLFW_PRESS))
  {
    input->poll();
    if(i > 5)
    {
      i = 0;
      graphics->render();
    }
    i++;
  }
}

Game::~Game()
{
  delete worldRenderer;
  delete world;
  delete input;
  delete graphics;
  delete myGL;
}

