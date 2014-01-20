#include "input.h"

#include "mygl.h"

Input::Input(MyGL& mygl)
{
  window = mygl.window;
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void Input::poll()
{
    glfwPollEvents();
}

