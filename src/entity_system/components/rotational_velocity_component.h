#ifndef _ROTATIONAL_VELOCITY_COMPONENT_H_
#define _ROTATIONAL_VELOCITY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class RotationalVelocityComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 rotVel;
};

#endif

