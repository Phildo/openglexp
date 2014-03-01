#include "graphics.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <cmath>

#define WIDTH 128
#define HEIGHT 256

void resize(GLFWwindow* window, int width, int height)
{
  //snap to power-of-two's
  int w; for(w = 2; (std::abs(width-(w*2))  < std::abs(width-w));  w *= 2) ;
  int h; for(h = 2; (std::abs(height-(h*2)) < std::abs(height-h)); h *= 2) ;

  glViewport(0, 0, w, h);
  //glfwSetWindowSize(window, w, h);
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

