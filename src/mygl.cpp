#include "mygl.h"
#include <stdlib.h>
#include <cmath>

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 256

void err(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

void resize(GLFWwindow* window, int width, int height)
{
  //snap to power-of-two's
  int w; for(w = 2; (std::abs(width-(w*2))  <= std::abs(width-w));  w *= 2) ;
  int h; for(h = 2; (std::abs(height-(h*2)) <= std::abs(height-h)); h *= 2) ;

  //Not static- how to communicate change to Graphics:: ?
  //sWidth  = w;
  //sHeight = h;
  glViewport(0, 0, w*2, h*2); 
  //glfwSetWindowSize(window, w, h); //can't call this every time- need to find a way to wait until drag stopped
}

MyGL::MyGL()
{
  glfwSetErrorCallback(err);
  glfwInit();

  //Get mac's "experimental" crap
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"hello world",NULL,NULL);
  glfwMakeContextCurrent(window);

  //must come after glfwCreateWindow
  glewExperimental = GL_TRUE;
  glewInit();

  //force through resize for retina handling
  int w, h;
  glfwGetWindowSize(window, &w, &h);
  resize(window, w, h);

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

  glClearColor(0,0,0,1);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

MyGL::~MyGL()
{
  glfwDestroyWindow(window);
  glfwTerminate();
}

