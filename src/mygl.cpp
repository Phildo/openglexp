#include "mygl.h"

void err(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

MyGL::MyGL()
{
  glfwSetErrorCallback(err);
  glfwInit();

  //Get mac's "experimental" crap
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(512,256,"hello world",NULL,NULL);
  glfwMakeContextCurrent(window);
}

MyGL::~MyGL()
{
  glfwDestroyWindow(window);
  glfwTerminate();
}

