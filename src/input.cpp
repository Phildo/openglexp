#include "input.h"

Input::Input(const MyGL* mygl)
{
  window = mygl->window;
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void Input::poll()
{
    glfwPollEvents();
}

