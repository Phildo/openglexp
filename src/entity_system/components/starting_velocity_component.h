#ifndef _STARTING_VELOCITY_COMPONENT_H_
#define _STARTING_VELOCITY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class StartingVelocityComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 startVel;
};

#endif

