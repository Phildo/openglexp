#include "bilboard_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "world_component.h"

#include "FLAT_utils.h"
#include "gl_include.h"
#include <stdlib.h>

BilboardEntityFactory::BilboardEntityFactory()
{
}

BilboardEntityFactory::~BilboardEntityFactory()
{
}

void BilboardEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity(ComponentSig_World);  

  WorldComponent& rc = ep->worldComponents[e.worldComponentIndex];
  rc.posData[0] = glm::vec3(-10.0,-10.0,0.0);
  rc.posData[1] = glm::vec3(-10.0, 10.0,0.0);
  rc.posData[2] = glm::vec3( 10.0, 10.0,0.0);
  rc.posData[3] = glm::vec3(-10.0,-10.0,0.0);
  rc.posData[4] = glm::vec3( 10.0, 10.0,0.0);
  rc.posData[5] = glm::vec3( 10.0,-10.0,0.0);
  rc.numVerts = 6;

}

