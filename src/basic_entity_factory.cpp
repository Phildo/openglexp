#include "basic_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "geo_component.h"

#include "FLAT_utils.h"
#include "gl_include.h"
#include <stdlib.h>

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
  pc.x = 0.0f;
  pc.y = 0.0f;
  pc.z = 0.0f;
  pc.velX = 0.0f;
  pc.velY = 0.0f;
  pc.velZ = 0.0f;

  pc.rotVelPitch = (FLAT_Utils::randf()-1.0f)*1;
  pc.rotVelYaw = (FLAT_Utils::randf()-1.0f)*1;
  pc.rotVelRoll = (FLAT_Utils::randf()-1.0f)*0.1;
}

