#ifndef _BASIC_RECONCILER_H_
#define _BASIC_RECONCILER_H_

#include "reconciler.h"

class BasicReconciler : public Reconciler
{
  private:
  public:
    BasicReconciler();
    ~BasicReconciler();

    void reconcile(Entity& e, EntityPool& ep) const;
};

#endif

