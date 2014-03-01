#include "graphics.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <cmath>

void resize(GLFWwindow* window, int width, int height)
{
  //snap to power-of-two's
  int w; for(w = 2; (std::abs(width-(w*2))  <= std::abs(width-w));  w *= 2) ;
  int h; for(h = 2; (std::abs(height-(h*2)) <= std::abs(height-h)); h *= 2) ;

  //Not static- how to communicate change to Graphics:: ?
  //sWidth  = w;
  //sHeight = h;
  glViewport(0, 0, w*2, h*2); //don't know why *2 is necessary...?
  //glfwSetWindowSize(window, w, h);
}

Graphics::Graphics(const MyGL* mygl)
{
  window = mygl->window;
  glfwGetWindowSize(window, &sWidth, &sHeight);
  resize(window, sWidth, sHeight);

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

  glClearColor(255,255,255,0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

Graphics::~Graphics()
{
}

