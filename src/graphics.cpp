#include "graphics.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stdlib.h>

#define WIDTH 64
#define LENGTH 64

void resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

Graphics::Graphics(const MyGL* mygl)
{
  window = mygl->window;

  //must come after glfwCreateWindow
  glewExperimental = GL_TRUE;
  glewInit();

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

  glClearColor(255,255,255,0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

Graphics::~Graphics()
{
}

