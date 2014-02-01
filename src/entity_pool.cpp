#include "entity_pool.h"

EntityPool::EntityPool()
{

}

EntityPool::~EntityPool()
{

}

//This is so not thread safe it isn't even funny
int EntityPool::createEntity(bool physics, bool render)
{
  Entity& e = entities.make();

  if(physics)
  {
    PhysicsComponent& pc = physicsComponents.make();
    e.physicsComponentIndex = physicsComponents.size - 1;
    pc.entityIndex = entities.size - 1;
  }

  if(render)
  {
    RenderComponent& rc = renderComponents.make();
    e.renderComponentIndex = renderComponents.size - 1;
    rc.entityIndex = entities.size - 1;
  }

  return entities.size - 1;
}

//Again- not thread safe at all. I'm a terrible person.
void EntityPool::deleteEntity(int index)
{
  Entity& e = entities[index];

  //Remove components and re-wire entities' component positions
  if(e.physicsComponentIndex > -1)
  {
    physicsComponents.remove(e.physicsComponentIndex);
    if(e.physicsComponentIndex != physicsComponents.size)
      entities[physicsComponents[e.physicsComponentIndex].entityIndex].physicsComponentIndex = e.physicsComponentIndex;
  }
  if(e.renderComponentIndex > -1)
  {
    renderComponents.remove(e.renderComponentIndex);
    if(e.renderComponentIndex != renderComponents.size)
      entities[renderComponents[e.renderComponentIndex].entityIndex].renderComponentIndex = e.renderComponentIndex;
  }

  //Remove entity and re-wire components' entity positions
  entities.remove(index);
  if(index != entities.size)
  {
    e = entities[index];
    if(e.physicsComponentIndex > -1)
      physicsComponents[e.physicsComponentIndex].entityIndex = index;
    if(e.renderComponentIndex > -1)
      renderComponents[e.renderComponentIndex].entityIndex = index;
  }
}

