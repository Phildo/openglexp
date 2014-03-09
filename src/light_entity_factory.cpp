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
  LightComponent& lc = ep->lightComponents[e.lightComponentIndex];
  //lc.pos[0] = -10.0;
}

