#include "game.h"
#include "gl_include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Game::run()
{
  int i = 0;
  while(!glfwWindowShouldClose(myGL->window) && (glfwGetKey(myGL.window, GLFW_KEY_ESCAPE) != GLFW_PRESS))
  {
    input.poll();
    if(i > 5)
    {
      i = 0;
      graphics.render();
    }
    i++;
  }
}

