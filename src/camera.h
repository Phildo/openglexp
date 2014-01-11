#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "gl_include.h"

class Camera
{
  private:
  public:
    glm::mat4 projMat;
    glm::mat4 viewMat;
    Camera();
    ~Camera();
};

#endif

