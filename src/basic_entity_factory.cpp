#include "basic_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "render_component.h"

#include "FLAT_utils.h"
#include "gl_include.h"
#include <stdlib.h>

BasicEntityFactory::BasicEntityFactory()
{
}

BasicEntityFactory::~BasicEntityFactory()
{
}

void BasicEntityFactory::produce(EntityPool& ep)
{
  Entity& e = ep.createEntity(ComponentSig_Physics | ComponentSig_Render);  

  RenderComponent& rc = ep.renderComponentForEntity(e);
  float r1;
  float r2;
  float r3;
  for(int i = 0; i < 3; i++)
  {
    r1 = (FLAT_Utils::randf()-1.0f)*2.0;
    r2 = (FLAT_Utils::randf()-1.0f)*2.0;
    r3 = (FLAT_Utils::randf()-1.0f)*2.0;
    rc.posData[i] = glm::vec3(r1,r2,r3);
  }

  PhysicsComponent& pc = ep.physicsComponentForEntity(e);
  pc.x = 0.0f;
  pc.y = 0.0f;
  pc.z = 0.0f;
  pc.velX = 0.0f;
  pc.velY = 0.0f;
  pc.velZ = 0.0f;

  pc.rotVelPitch = (FLAT_Utils::randf()-1.0f)*0.25f;
  pc.rotVelYaw = (FLAT_Utils::randf()-1.0f)*0.25f;
  pc.rotVelRoll = (FLAT_Utils::randf()-1.0f)*0.25f;
}

