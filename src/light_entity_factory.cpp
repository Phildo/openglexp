#include "light_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "light_component.h"

#include "gl_include.h"

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
  pc.vel.x = 0.01;
  pc.vel.y = 0.01;
  pc.vel.z = 0.01;
  pc.pos.x = -10;
  pc.pos.y = -10;
  pc.pos.z = -10;
  LightComponent& lc = ep->lightComponents[e.lightComponentIndex]; //note- physics pos will override light pos given opportunity
  lc.pos.x = -10;
  lc.pos.y = -10;
  lc.pos.z = -10;
}

