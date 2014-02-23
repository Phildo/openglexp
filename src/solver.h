#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "physics_component.h"

class Solver
{
  private:
  public:
    virtual ~Solver() {};
    virtual void solve(PhysicsComponent& pc) const = 0;
};

#endif

