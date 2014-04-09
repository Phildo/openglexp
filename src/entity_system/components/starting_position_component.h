#ifndef _STARTING_POSITION_COMPONENT_H_
#define _STARTING_POSITION_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class StartingPositionComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 startPos;
};

#endif

