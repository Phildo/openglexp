#ifndef _BILBOARD_GEOMETRY_COMPONENT_H_
#define _BILBOARD_GEOMETRY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class BilboardGeometryComponent
{
  private:
  public:
    BilboardGeometryComponent() : modelMatR(1.0), modelMatA(1.0) { }

    Entity* entity;

    glm::mat4 modelMatR;
    glm::mat4 modelMatA;
};

#endif

