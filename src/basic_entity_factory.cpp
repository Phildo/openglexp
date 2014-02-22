#include "basic_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "render_component.h"

#include <stdlib.h>

BasicEntityFactory::BasicEntityFactory()
{
}

BasicEntityFactory::~BasicEntityFactory()
{
}

void BasicEntityFactory::produce(EntityPool& ep)
{
  int ei = ep.createEntity(ComponentSig_Physics | ComponentSig_Render);  

  RenderComponent& rc = ep.renderComponentForEntityIndex(ei);
  float r1;
  float r2;
  float r3;
  for(int i = 0; i < 3; i++)
  {
    r1 = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/2)) - 1.0f;
    r2 = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/2)) - 1.0f;
    r3 = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/2)) - 1.0f;
    rc.posData[i] = glm::vec3(r1,r2,r3);
  }
}

