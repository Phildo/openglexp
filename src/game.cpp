#include "game.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Game::Game()
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  window = glfwCreateWindow(640,480,"hello world",NULL,NULL);
  glfwMakeContextCurrent(window);
  glewExperimental = GL_TRUE;
  glewInit();

  printf("shader lang: %s\n",glGetString(GL_SHADING_LANGUAGE_VERSION));
  graphics = new Graphics(window);
}

void Game::run()
{
  //move to input handler later
  //glfwSetKeyCallback(window, keyPress);
  //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  int i = 0;
  while(!glfwWindowShouldClose(window) && (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS))
  {
    if(i > 50000)
    {
      i = 0;
      graphics->render();
    }

    //move to input handler
    glfwPollEvents();

    i++;
  }
}

