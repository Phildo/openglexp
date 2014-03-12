#include "light_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "light_component.h"

#include "gl_include.h"
#include "FLAT_utils.h"

#include <stdlib.h>
#include <iostream>

LightEntityFactory::LightEntityFactory()
{
}

LightEntityFactory::~LightEntityFactory()
{
}

void LightEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity( ComponentSig_Light | ComponentSig_Physics | ComponentSig_InputPlanar );  
  PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];
  pc.vel.x = 0;
  pc.vel.y = 0;
  pc.vel.z = 0;
  pc.pos.x = 0;
  pc.pos.y = 0;
  pc.pos.z = -1;
  LightComponent& lc = ep->lightComponents[e.lightComponentIndex]; //note- physics pos will override light pos given opportunity
  lc.pos.x = 0;
  lc.pos.y = 0;
  lc.pos.z = 5;
}

