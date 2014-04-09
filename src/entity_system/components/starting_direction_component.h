#ifndef _STARTING_DIRECTION_COMPONENT_H_
#define _STARTING_DIRECTION_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class StartingDirectionComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 startDir;
};

#endif

