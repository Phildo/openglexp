#include "game.h"
#include "graphics.h"

Game::Game()
{
  window = glfwCreateWindow(640,480,"hello world",NULL,NULL);
  glewExperimental = GL_TRUE;
  glewInit();
  graphics = new Graphics(window);
}

void Game::run()
{
  //move to input handler
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

