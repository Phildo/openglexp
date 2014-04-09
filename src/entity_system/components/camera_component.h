#ifndef _CAMERA_COMPONENT_H_
#define _CAMERA_COMPONENT_H_

#include "gl_include.h"
class Entity;

class CameraComponent
{
  private:
  public:
    Entity* entity;

    float nearPlane;
    float farPlane;
    float fov;
    glm::mat4 projMat();
    glm::mat4 viewMat();
};

#endif

