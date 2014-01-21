#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "mygl.h"

class Graphics
{
  private:
    GLFWwindow* window;
    GLuint gl_vertBufferID;
    GLuint gl_colorBufferID;
    GLuint gl_projMatrixID;
    GLuint gl_viewMatrixID;
    GLuint gl_modelMatrixID;
    glm::mat4 modelMat;
  public:
    Graphics(const MyGL& mygl);
    ~Graphics();
    void render();
};

#endif

