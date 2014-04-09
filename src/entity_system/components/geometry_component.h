#ifndef _GEOMETRY_COMPONENT_H_
#define _GEOMETRY_COMPONENT_H_

#include <glm/glm.hpp>
#define MAX_GEO_VERTS 20
class Entity;

class GeometryComponent
{
  private:
  public:
    Entity* entity;

    int numVerts;
    glm::vec3 pos[MAX_GEO_VERTS];
    glm::vec3 color[MAX_GEO_VERTS];
    glm::vec3 norm[MAX_GEO_VERTS];
    glm::mat4 modelMatR;
    glm::mat4 modelMatA;
};

#endif

