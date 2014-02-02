#ifndef _PHYSICS_COMPONENT_H_
#define _PHYSICS_COMPONENT_H_

#include "component.h"

class PhysicsComponent : public Component
{
  private:
    float x;
    float y;
    float z;
    float velX;
    float velY;
    float velZ;
  public:
    PhysicsComponent();
    ~PhysicsComponent();
};

#endif

