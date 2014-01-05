#include "input.h"

Input::Input(GLFWwindow* win)
{
  window = win;
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void Input::poll()
{
    glfwPollEvents();
}
