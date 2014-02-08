#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "mygl.h"

class Graphics
{
  private:
    GLFWwindow* window;
  public:
    Graphics(const MyGL& mygl);
    ~Graphics();
};

#endif

