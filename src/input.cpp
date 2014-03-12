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
    up   = (glfwGetKey(window, GLFW_KEY_UP)   == GLFW_PRESS);
    down = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);
    w    = (glfwGetKey(window, GLFW_KEY_W)    == GLFW_PRESS);
    a    = (glfwGetKey(window, GLFW_KEY_A)    == GLFW_PRESS);
    s    = (glfwGetKey(window, GLFW_KEY_S)    == GLFW_PRESS);
    d    = (glfwGetKey(window, GLFW_KEY_D)    == GLFW_PRESS);
}

Input::~Input()
{

}

