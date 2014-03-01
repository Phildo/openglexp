#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "mygl.h"

class Graphics
{
  private:
    GLFWwindow* window;
  public:
    int sWidth;
    int sHeight;
    Graphics(const MyGL* mygl);
    ~Graphics();
};

#endif

