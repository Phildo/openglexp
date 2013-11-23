#include "input.h"

Input::Input(GLFWwindow* win)
{
  window = win;
  //glfwSetKeyCallback(window, keyPress);
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void Input::poll()
{
    glfwPollEvents();
}
