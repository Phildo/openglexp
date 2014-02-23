#ifndef _BASIC_SOLVER_H_
#define _BASIC_SOLVER_H_

#include "solver.h"

class BasicSolver : public Solver
{
  private:
  public:
    BasicSolver();
    ~BasicSolver();

    void solve(PhysicsComponent& pc) const;
};

#endif

