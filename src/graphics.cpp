#include "graphics.h"

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
  glViewport(0, 0, w, h); 
  //glfwSetWindowSize(window, w, h); //can't call this every time- need to find a way to wait until drag stopped
}

Graphics::Graphics(const MyGL* mygl)
{
  window = mygl->window;
  glfwGetWindowSize(window, &sWidth, &sHeight);
  //For retina...
  //sWidth*=2;
  //sHeight*=2;
  resize(window, sWidth, sHeight);

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

  glClearColor(0,0,0,1);//(255,255,255,0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

Graphics::~Graphics()
{
}

