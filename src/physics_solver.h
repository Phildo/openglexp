#ifndef _PHYSICS_SOLVER_H_
#define _PHYSICS_SOLVER_H_

#include "entity_system/components/spacial_component.h"

class PhysicsSolver
{
  private:
  public:
    PhysicsSolver();
    ~PhysicsSolver();

    void solve(SpacialComponent& pc) const;
};

#endif

