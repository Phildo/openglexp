#ifndef _ROTATIONAL_VELOCITY_COMPONENT_H_
#define _ROTATIONAL_VELOCITY_COMPONENT_H_

#include <glm/glm.hpp>

class RotationalVelocityComponent
{
  private:
  public:
    int entityIndex;
    glm::vec3 rotVel;
};

#endif

