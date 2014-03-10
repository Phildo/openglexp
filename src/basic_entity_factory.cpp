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
  gc.color[0].r = FLAT_Utils::randf();
  gc.color[0].g = FLAT_Utils::randf();
  gc.color[0].b = FLAT_Utils::randf();
  gc.color[1].r = FLAT_Utils::randf();
  gc.color[1].g = FLAT_Utils::randf();
  gc.color[1].b = FLAT_Utils::randf();
  gc.color[2].r = FLAT_Utils::randf();
  gc.color[2].g = FLAT_Utils::randf();
  gc.color[2].b = FLAT_Utils::randf();

  PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];

  pc.rotVel.y = (FLAT_Utils::randf()-0.5f)*0.5;
  pc.rotVel.x = 0;//(FLAT_Utils::randf()-0.5f)*2;
  pc.rotVel.z = 0;//(FLAT_Utils::randf()-0.5f)*2;
}

