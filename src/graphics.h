#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "gl_include.h"

class Graphics
{
  private:
    GLFWwindow* window;
    GLuint vertBufferID;
    GLuint vertArrayID;
    GLuint ModelMatrixID;
    GLuint ViewMatrixID;
    GLuint ProjMatrixID;
  public:
    Graphics(GLFWwindow* win);
    ~Graphics();
    void render();
};

#endif

