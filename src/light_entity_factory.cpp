#include "light_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "light_component.h"

#include "FLAT_utils.h"
#include "gl_include.h"
#include <stdlib.h>

LightEntityFactory::LightEntityFactory()
{
}

LightEntityFactory::~LightEntityFactory()
{
}

void LightEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity( ComponentSig_Light );  
  LightComponent& lc = ep->lightComponents[e.lightComponentIndex];
  //lc.pos[0] = -10.0;
}

