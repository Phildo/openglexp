#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "mygl.h"

class Graphics
{
  private:
    GLFWwindow* window;
    //void resize(GLFWwindow* window, int width, int height);
  public:
    int winWidth;
    int winHeight;
    Graphics(const MyGL* mygl);
    ~Graphics();
};

#endif

