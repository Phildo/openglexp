#ifndef _INPUT_H_
#define _INPUT_H_

#include "mygl.h"

class Input
{
  private:
    GLFWwindow* window;
  public:
    Input(const MyGL* mygl);
    void poll();
};

#endif
