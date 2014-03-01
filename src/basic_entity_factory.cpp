#include "basic_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "world_component.h"

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
  Entity& e = ep->createEntity(ComponentSig_Physics | ComponentSig_World | ComponentSig_HUD);  

  WorldComponent& rc = ep->worldComponents[e.worldComponentIndex];

  PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];
  pc.x = 0.0f;
  pc.y = 0.0f;
  pc.z = 0.0f;
  pc.velX = 0.0f;
  pc.velY = 0.0f;
  pc.velZ = 0.0f;

  pc.rotVelPitch = 0.001;//(FLAT_Utils::randf()-1.0f);
  pc.rotVelYaw = 0.001;//(FLAT_Utils::randf()-1.0f);
  pc.rotVelRoll = 0.1;//(FLAT_Utils::randf()-1.0f);
}

