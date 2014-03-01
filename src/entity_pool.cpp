#include "entity_pool.h"

EntityPool::EntityPool()
{

}

EntityPool::~EntityPool()
{

}

//This is so not thread safe it isn't even funny
Entity& EntityPool::createEntity(component_signature csig)
{
  Entity e;

  if(csig & ComponentSig_Physics)
  {
    PhysicsComponent pc;
    e.physicsComponentIndex = physicsComponents.size();
    pc.entityIndex = entities.size();
    physicsComponents.push_back(std::move(pc));
  }

  if(csig & ComponentSig_Render)
  {
    RenderComponent rc;
    e.renderComponentIndex = renderComponents.size();
    rc.entityIndex = entities.size();
    renderComponents.push_back(std::move(rc));
  }

  entities.push_back(std::move(e));
  return entities[entities.size() - 1];
}

//Again- not thread safe at all. I'm a terrible person.
void EntityPool::deleteEntity(int index)
{
  Entity& e = entities[index];

  //Remove components and re-wire entities' component positions
  if(e.physicsComponentIndex > -1)
  {
    physicsComponents.erase(physicsComponents.begin()+e.physicsComponentIndex);
    if(e.physicsComponentIndex != physicsComponents.size())
      entities[physicsComponents[e.physicsComponentIndex].entityIndex].physicsComponentIndex = e.physicsComponentIndex;
  }
  if(e.renderComponentIndex > -1)
  {
    renderComponents.erase(renderComponents.begin()+e.renderComponentIndex);
    if(e.renderComponentIndex != renderComponents.size())
      entities[renderComponents[e.renderComponentIndex].entityIndex].renderComponentIndex = e.renderComponentIndex;
  }

  //Remove entity and re-wire components' entity positions
  entities.erase(entities.begin()+index);
  if(index != entities.size())
  {
    e = entities[index];
    if(e.physicsComponentIndex > -1)
      physicsComponents[e.physicsComponentIndex].entityIndex = index;
    if(e.renderComponentIndex > -1)
      renderComponents[e.renderComponentIndex].entityIndex = index;
  }
}

