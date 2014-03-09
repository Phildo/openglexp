#ifndef _LIGHT_ENTITY_FACTORY_H_
#define _LIGHT_ENTITY_FACTORY_H_

#include "entity_factory.h"

class EntityPool;

class LightEntityFactory : public EntityFactory
{
  private:
  public:
    LightEntityFactory();
    ~LightEntityFactory();
    void produce(EntityPool* ep);
};

#endif

