#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "gl_include.h"

class Graphics
{
  private:
    GLFWwindow* window;
    GLuint vertBufferID;
    GLuint vertArrayID;
    GLuint ProjMatrixID;
    GLuint ViewMatrixID;
    GLuint ModelMatrixID;
    glm::mat4 ProjMat;
    glm::mat4 ViewMat;
    glm::mat4 ModelMat;
  public:
    Graphics(GLFWwindow* win);
    ~Graphics();
    void render();
};

#endif

