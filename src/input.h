#ifndef _INPUT_H_
#define _INPUT_H_

#include "gl_include.h"

class MyGL;

class Input
{
  private:
    GLFWwindow* window;
  public:
    Input(const MyGL& mygl);
    void poll();
};

#endif
