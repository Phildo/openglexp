#ifndef _STARTING_ROTATIONAL_VELOCITY_COMPONENT_H_
#define _STARTING_ROTATIONAL_VELOCITY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class StartingRotationalVelocityComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 startRotVel;
};

#endif

