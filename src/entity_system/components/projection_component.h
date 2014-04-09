#ifndef _PROJECTION_COMPONENT_H_
#define _PROJECTION_COMPONENT_H_

#include "gl_include.h"
class Entity;

class ProjectionComponent
{
  private:
  public:
    Entity* entity;

    float nearPlane;
    float farPlane;
    float fov;
    glm::mat4 projMat();
};

#endif

