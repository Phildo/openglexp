#ifndef _RECONCILER_H_
#define _RECONCILER_H_

#include "entity.h"
#include "entity_pool.h"

class Reconciler
{
  private:
  public:
    virtual ~Reconciler() {};
    virtual void reconcile(Entity& e, EntityPool& ep) const = 0;
};

#endif

