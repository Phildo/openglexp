#ifndef _INPUT_H_
#define _INPUT_H_

#include "gl_include.h"

class Input
{
  private:
    GLFWwindow* window;
  public:
    Input(GLFWwindow* win);
    void poll();
};

#endif
