#ifndef _BASIC_RECONCILER_H_
#define _BASIC_RECONCILER_H_

#include "entity.h"
#include "entity_pool.h"

class BasicReconciler
{
  private:
  public:
    BasicReconciler();
    ~BasicReconciler();

    void reconcile(Entity& e, EntityPool* ep) const;
};

#endif

