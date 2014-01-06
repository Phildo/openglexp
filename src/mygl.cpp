#include "mygl.h"
#include "gl_include.h"

void err(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

MyGL::MyGL()
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
}

MyGL::~MyGL()
{
  glfwTerminate();
}

