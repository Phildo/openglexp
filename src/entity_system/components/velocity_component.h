#ifndef _VELOCITY_COMPONENT_H_
#define _VELOCITY_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class VelocityComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 vel;
};

#endif

