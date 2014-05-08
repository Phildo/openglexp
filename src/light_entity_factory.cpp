#include "light_entity_factory.h"
#include "entity_system/entity_pool.h"

#include "FLAT_utils.h"

void LightEntityFactory::produce(EntityPool* ep)
{
  Entity* e = ep->createEntity( component_signature_light_component | component_signature_spacial_component | component_signature_geometry_inv_cube_model );  
  e->spacial_component->vel.x = -0.000001f;
  e->spacial_component->vel.y = 0.0000001f;
  e->spacial_component->vel.z = -0.000001f;
  e->spacial_component->pos.x = (FLAT_Utils::randf()-0.5f)*30;
  e->spacial_component->pos.y = (FLAT_Utils::randf()-0.5f)*30;
  e->spacial_component->pos.z = (FLAT_Utils::randf())*20;
}

