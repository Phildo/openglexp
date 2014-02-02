#include "basic_entity_factory.h"

#include "entity.h"
#include "component.h"
#include "entity_pool.h"

BasicEntityFactory::BasicEntityFactory()
{
}

BasicEntityFactory::~BasicEntityFactory()
{
}

void BasicEntityFactory::produce(EntityPool& ep)
{
  ep.createEntity(false, true);  
}

