#include "basic_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "geo_component.h"

#include "FLAT_utils.h"
#include "gl_include.h"

BasicEntityFactory::BasicEntityFactory()
{
}

BasicEntityFactory::~BasicEntityFactory()
{
}

void BasicEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity( ComponentSig_Physics | ComponentSig_Geo );  

  GeoComponent& gc = ep->geoComponents[e.geoComponentIndex];

  PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];

  pc.rotVel.y = (FLAT_Utils::randf()-1.0f);
  pc.rotVel.x = (FLAT_Utils::randf()-1.0f);
  pc.rotVel.z = (FLAT_Utils::randf()-1.0f);
}

