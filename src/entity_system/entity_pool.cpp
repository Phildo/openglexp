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

  if(csig & ComponentSig_InputPlanar)
  {
    InputPlanarComponent ipc;
    e.inputPlanarComponentIndex = inputPlanarComponents.size();
    ipc.entityIndex = entities.size();
    inputPlanarComponents.push_back(std::move(ipc));
  }

  if(csig & ComponentSig_Geo)
  {
    GeoComponent gc;
    e.geoComponentIndex = geoComponents.size();
    gc.entityIndex = entities.size();
    geoComponents.push_back(std::move(gc));
  }

  if(csig & ComponentSig_Light)
  {
    LightComponent lc;
    e.lightComponentIndex = lightComponents.size();
    lc.entityIndex = entities.size();
    lightComponents.push_back(std::move(lc));
  }

  if(csig & ComponentSig_HUD)
  {
    HUDComponent hc;
    e.HUDComponentIndex = HUDComponents.size();
    hc.entityIndex = entities.size();
    HUDComponents.push_back(std::move(hc));
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
  if(e.inputPlanarComponentIndex > -1)
  {
    inputPlanarComponents.erase(inputPlanarComponents.begin()+e.inputPlanarComponentIndex);
    if(e.inputPlanarComponentIndex != inputPlanarComponents.size())
      entities[inputPlanarComponents[e.inputPlanarComponentIndex].entityIndex].inputPlanarComponentIndex = e.inputPlanarComponentIndex;
  }
  if(e.geoComponentIndex > -1)
  {
    geoComponents.erase(geoComponents.begin()+e.geoComponentIndex);
    if(e.geoComponentIndex != geoComponents.size())
      entities[geoComponents[e.geoComponentIndex].entityIndex].geoComponentIndex = e.geoComponentIndex;
  }
  if(e.lightComponentIndex > -1)
  {
    lightComponents.erase(lightComponents.begin()+e.lightComponentIndex);
    if(e.lightComponentIndex != lightComponents.size())
      entities[lightComponents[e.lightComponentIndex].entityIndex].lightComponentIndex = e.lightComponentIndex;
  }
  if(e.HUDComponentIndex > -1)
  {
    HUDComponents.erase(HUDComponents.begin()+e.HUDComponentIndex);
    if(e.HUDComponentIndex != HUDComponents.size())
      entities[HUDComponents[e.HUDComponentIndex].entityIndex].HUDComponentIndex = e.HUDComponentIndex;
  }

  //Remove entity and re-wire components' entity positions
  entities.erase(entities.begin()+index);
  if(index != entities.size())
  {
    e = entities[index];
    if(e.physicsComponentIndex > -1)
      physicsComponents[e.physicsComponentIndex].entityIndex = index;
    if(e.inputPlanarComponentIndex > -1)
      inputPlanarComponents[e.inputPlanarComponentIndex].entityIndex = index;
    if(e.geoComponentIndex > -1)
      geoComponents[e.geoComponentIndex].entityIndex = index;
    if(e.lightComponentIndex > -1)
      lightComponents[e.lightComponentIndex].entityIndex = index;
    if(e.HUDComponentIndex > -1)
      HUDComponents[e.HUDComponentIndex].entityIndex = index;
  }
}

