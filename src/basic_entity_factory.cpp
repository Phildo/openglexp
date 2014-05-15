#include "basic_entity_factory.h"
#include "entity_system/entity_pool.h"
#include "entity_system/models.h"

#include "FLAT_utils.h"

void BasicEntityFactory::produce(EntityPool* ep)
{
  Entity* e = ep->createEntity( component_signature_spacial_component | component_signature_geometry_inv_cube_model );  

  e->spacial_component->rotVel.y = (FLAT_Utils::randf()-0.5f)*2;
  e->spacial_component->rotVel.x = (FLAT_Utils::randf()-0.5f)*2;
  e->spacial_component->rotVel.z = (FLAT_Utils::randf()-0.5f)*2;

  e->spacial_component->rot.y = (FLAT_Utils::randf())*0;
  e->spacial_component->rot.x = (FLAT_Utils::randf())*0;
  e->spacial_component->rot.z = (FLAT_Utils::randf())*0;
}

