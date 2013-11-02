#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void err(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

void resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.f, 1.f, -1.f, 1.f, 1.f, -1.f);
  glMatrixMode(GL_MODELVIEW);
}

void keyPress(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  //if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
}

int main(int argc, char **argv)
{
  glfwSetErrorCallback(err);
  glfwInit();
  GLFWwindow* window = glfwCreateWindow(640,480,"",NULL,NULL);
  //glfwTerminate();
  glfwMakeContextCurrent(window);
  glfwSwapInterval(0);
  glfwSetWindowTitle(window, "yo");

  glfwSetFramebufferSizeCallback(window, resize);
  glfwSetKeyCallback(window, keyPress);

  glClearColor(255,255,255,0);
  glColor3d(0.0f,0.0f,0.0f);
  while(!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex2i(0,0);
    glVertex2i(0,128);
    glVertex2i(128,128);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  exit(EXIT_SUCCESS);
}

