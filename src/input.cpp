#include "input.h"

Input::Input(const MyGL& mygl)
{
  window = mygl.window;
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void Input::poll()
{
    glfwPollEvents();
}

