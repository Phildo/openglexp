#include "physics_component.h"

PhysicsComponent::PhysicsComponent()
{
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
  velX = 0.0f;
  velY = 0.0f;
  velZ = 0.0f;
  rotPitch = 0.0f;
  rotYaw = 0.0f;
  rotRoll = 0.0f;
  rotVelPitch = 0.0f;
  rotVelYaw = 0.0f;
  rotVelRoll = 0.0f;
}

PhysicsComponent::~PhysicsComponent()
{
}

