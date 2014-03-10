#include "light_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "light_component.h"

#include "gl_include.h"
#include "FLAT_utils.h"

LightEntityFactory::LightEntityFactory()
{
}

LightEntityFactory::~LightEntityFactory()
{
}

void LightEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity( ComponentSig_Light | ComponentSig_Physics );  
  PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];
  pc.vel.x = 0;//.01;
  pc.vel.y = 0;//.01;
  pc.vel.z = 0;//.01;
  pc.pos.x = 0;
  pc.pos.y = 0;
  pc.pos.z = 5*FLAT_Utils::randf();
  LightComponent& lc = ep->lightComponents[e.lightComponentIndex]; //note- physics pos will override light pos given opportunity
  lc.pos.x = 0;
  lc.pos.y = 0;
  lc.pos.z = 5;
}

