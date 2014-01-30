#include "entity_system.h"
#include "entity_pool.h"
#include "entity_factory.h"

EntitySystem::EntitySystem():pool()
{
}

EntitySystem::~EntitySystem()
{
}

void EntitySystem::produceEntityFromFactory(EntityFactory* ef)
{
  ef.produce(pool);
}

