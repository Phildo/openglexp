#include "graphics.h"

#include <GLFW/glfw3.h>

void resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.f, 1.f, -1.f, 1.f, 1.f, -1.f);
  glMatrixMode(GL_MODELVIEW);
}

Graphics::Graphics(GLFWwindow* win)
{
  window = win;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);
  glClearColor(255,255,255,0);
  glColor3d(0.0f,0.0f,0.0f);
}

void Graphics::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
  glVertex2i(0,0);
  glVertex2i(0,128);
  glVertex2i(128,128);
  glEnd();

  glfwSwapBuffers(window);
}

