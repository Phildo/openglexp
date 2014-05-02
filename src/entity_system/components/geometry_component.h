#ifndef _GEOMETRY_COMPONENT_H_
#define _GEOMETRY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class GeometryComponent
{
  private:
  public:
    Entity* entity;

    glm::mat4 modelMatR;
    glm::mat4 modelMatA;
};

#endif

