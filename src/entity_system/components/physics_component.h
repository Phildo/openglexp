#ifndef _PHYSICS_COMPONENT_H_
#define _PHYSICS_COMPONENT_H_

#include "gl_include.h"

class PhysicsComponent
{
  private:
  public:
    PhysicsComponent();
    ~PhysicsComponent();

    int entityIndex;

    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 rot;
    glm::vec3 rotVel;
};

#endif

