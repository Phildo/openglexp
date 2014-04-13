#ifndef _SPACIAL_COMPONENT_H_
#define _SPACIAL_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class SpacialComponent
{
  private:
  public:
    Entity* entity;

    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 rot;
    glm::vec3 rotVel;
};

#endif

