#include "basic_entity_factory.h"
#include "entity_system/entity_pool.h"
#include "entity_system/models.h"

#include "FLAT_utils.h"

void BasicEntityFactory::produce(EntityPool* ep)
{
  Entity* e = ep->createEntity( component_signature_spacial_component | component_signature_geometry_gear_model );  
}

