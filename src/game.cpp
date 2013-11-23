#include "game.h"
#include "gl_include.h"
#include "input.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

Game::Game()
{
  glfwSetErrorCallback(err);
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(640,480,"hello world",NULL,NULL);
  glfwMakeContextCurrent(window);
  glewExperimental = GL_TRUE;
  glewInit();

  input = new Input(window);
  graphics = new Graphics(window);
}

void Game::run()
{
  int i = 0;
  while(!glfwWindowShouldClose(window) && (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS))
  {
    input->poll();
    if(i > 5000)
    {
      i = 0;
      graphics->render();
    }
    i++;
  }
}

Game::~Game()
{
  delete graphics;
  delete input;
  glfwTerminate();
}

