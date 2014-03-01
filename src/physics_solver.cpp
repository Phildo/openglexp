#include "physics_solver.h"

PhysicsSolver::PhysicsSolver()
{
}

PhysicsSolver::~PhysicsSolver()
{
}

void PhysicsSolver::solve(PhysicsComponent& pc) const
{
  pc.x += pc.velX;
  pc.y += pc.velY;
  pc.z += pc.velZ;

  pc.rotPitch += pc.rotVelPitch;
  pc.rotYaw += pc.rotVelYaw;
  pc.rotRoll += pc.rotVelRoll;
}

