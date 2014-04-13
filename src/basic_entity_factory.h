#ifndef _BASIC_ENTITY_FACTORY_H_
#define _BASIC_ENTITY_FACTORY_H_

#include "entity_system/entity_factory.h"

class EntityPool;

class BasicEntityFactory : public EntityFactory
{
  private:
  public:
    BasicEntityFactory();
    ~BasicEntityFactory();
    void produce(EntityPool* ep);
};

#endif

