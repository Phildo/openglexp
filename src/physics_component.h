#ifndef _PHYSICS_COMPONENT_H_
#define _PHYSICS_COMPONENT_H_

class PhysicsComponent
{
  private:
  public:
    PhysicsComponent();
    ~PhysicsComponent();

    int entityIndex;

    float x;
    float y;
    float z;
    float velX;
    float velY;
    float velZ;
    float rotPitch;
    float rotYaw;
    float rotRoll;
    float rotVelPitch;
    float rotVelYaw;
    float rotVelRoll;
};

#endif

