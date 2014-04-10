#ifndef _TRIANGLE_MODEL_COMPONENT_H_
#define _TRIANGLE_MODEL_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class TriangleModelComponent
{
  private:
  public:
    Entity* entity;

    const int numVerts 6;
    glm::vec3 pos[numVerts];
    glm::vec3 color[numVerts];
    glm::vec3 norm[numVerts];
};

#endif

