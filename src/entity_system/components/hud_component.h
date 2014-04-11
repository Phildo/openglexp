#ifndef _HUD_COMPONENT_H_
#define _HUD_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class HudComponent
{
  private:
  public:
    Entity* entity;

    const int numVerts 4;
    glm::vec3 pos[numVerts];
    glm::vec3 color[numVerts];
};

#endif

