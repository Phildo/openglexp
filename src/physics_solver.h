#ifndef _PHYSICS_SOLVER_H_
#define _PHYSICS_SOLVER_H_

#include "physics_component.h"

class PhysicsSolver
{
  private:
  public:
    PhysicsSolver();
    ~PhysicsSolver();

    void solve(PhysicsComponent& pc) const;
};

#endif

