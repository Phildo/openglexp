#ifndef _DIRECTION_COMPONENT_H_
#define _DIRECTION_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class DirectionComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 dir;
};

#endif

