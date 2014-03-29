#ifndef _STARTING_ROTATIONAL_VELOCITY_COMPONENT_H_
#define _STARTING_ROTATIONAL_VELOCITY_COMPONENT_H_

#include <glm/glm.hpp>

class StartingRotationalVelocityComponent
{
  private:
  public:
    int entityIndex;
    glm::vec3 startRotVel;
};

#endif

