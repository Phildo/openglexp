#ifndef _PHYSICS_COMPONENT_H_
#define _PHYSICS_COMPONENT_H_

class PhysicsComponent
{
  private:
    float x;
    float y;
    float z;
    float velX;
    float velY;
    float velZ;
  public:
    int entityIndex;
    PhysicsComponent();
    ~PhysicsComponent();
};

#endif

