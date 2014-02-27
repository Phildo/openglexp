#ifndef _BASIC_SOLVER_H_
#define _BASIC_SOLVER_H_

#include "camera.h"
#include "physics_component.h"

class BasicSolver
{
  private:
  public:
    BasicSolver();
    ~BasicSolver();

    void solve(PhysicsComponent& pc) const;
};

#endif

