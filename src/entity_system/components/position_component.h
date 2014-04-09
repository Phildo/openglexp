#ifndef _POSITION_COMPONENT_H_
#define _POSITION_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class PositionComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 pos;
};

#endif

