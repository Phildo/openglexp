#ifndef _INPUT_H_
#define _INPUT_H_

#include "mygl.h"

class Input
{
  private:
    GLFWwindow* window;
  public:
    Input(const MyGL* mygl);
    ~Input();

    bool up;
    bool down;
    bool w;
    bool a;
    bool s;
    bool d;

    void poll();
};

#endif
