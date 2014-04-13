#include "bilboard_entity_factory.h"

#include "entity_system/entity.h"
#include "entity_system/entity_pool.h"
#include "entity_system/components/geometry_component.h"

#include "gl_include.h"

BilboardEntityFactory::BilboardEntityFactory()
{
}

BilboardEntityFactory::~BilboardEntityFactory()
{
}

void BilboardEntityFactory::produce(EntityPool* ep)
{
  Entity* e = ep->createEntity( component_signature_geometry_component );  
  e->geometry_component->model = 2; //BILBOARD_MODEL
}

