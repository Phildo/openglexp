#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

#include "entity_pool.h"

class EntityFactory;

class EntitySystem
{
  private:
    EntityPool pool;
  public:
    EntitySystem();
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);
};

#endif

