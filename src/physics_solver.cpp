#include "physics_solver.h"

PhysicsSolver::PhysicsSolver()
{
}

PhysicsSolver::~PhysicsSolver()
{
}

void PhysicsSolver::solve(SpacialComponent& pc) const
{
  pc.pos.x += pc.vel.x;
  pc.pos.y += pc.vel.y;
  pc.pos.z += pc.vel.z;

  pc.rot.y += pc.rotVel.y; //yaw
  pc.rot.x += pc.rotVel.x; //pitch
  pc.rot.z += pc.rotVel.z; //roll
}

