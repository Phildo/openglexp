#ifndef _BILBOARD_ENTITY_FACTORY_H_
#define _BILBOARD_ENTITY_FACTORY_H_

#include "entity_system/entity_factory.h"

class EntityPool;

class BilboardEntityFactory : public EntityFactory
{
  private:
  public:
    BilboardEntityFactory();
    ~BilboardEntityFactory();
    void produce(EntityPool* ep);
};

#endif

