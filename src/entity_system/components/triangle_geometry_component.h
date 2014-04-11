#ifndef _TRIANGLE_GEOMETRY_COMPONENT_H_
#define _TRIANGLE_GEOMETRY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class TriangleGeometryComponent
{
  private:
  public:
    TriangleGeometryComponent() : modelMatR(1.0), modelMatA(1.0) { }

    Entity* entity;

    glm::mat4 modelMatR;
    glm::mat4 modelMatA;
};

#endif

