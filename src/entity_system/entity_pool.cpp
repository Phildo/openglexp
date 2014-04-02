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

//ECS_CONSTRUCT_ADD_C_TO_E_START

if(csig & component_signature_direction_component)
{
  DirectionComponent direction_component;
  direction_components.push_back(std::move(direction_component));
  e.direction_component = &direction_components[direction_components.size()-1];
  direction_component.entity = &e;
}


if(csig & component_signature_geometry_component)
{
  GeometryComponent geometry_component;
  geometry_components.push_back(std::move(geometry_component));
  e.geometry_component = &geometry_components[geometry_components.size()-1];
  geometry_component.entity = &e;
}


if(csig & component_signature_hud_component)
{
  HudComponent hud_component;
  hud_components.push_back(std::move(hud_component));
  e.hud_component = &hud_components[hud_components.size()-1];
  hud_component.entity = &e;
}


if(csig & component_signature_input_component)
{
  InputComponent input_component;
  input_components.push_back(std::move(input_component));
  e.input_component = &input_components[input_components.size()-1];
  input_component.entity = &e;
}


if(csig & component_signature_light_component)
{
  LightComponent light_component;
  light_components.push_back(std::move(light_component));
  e.light_component = &light_components[light_components.size()-1];
  light_component.entity = &e;
}


if(csig & component_signature_position_component)
{
  PositionComponent position_component;
  position_components.push_back(std::move(position_component));
  e.position_component = &position_components[position_components.size()-1];
  position_component.entity = &e;
}


if(csig & component_signature_rotational_velocity_component)
{
  RotationalVelocityComponent rotational_velocity_component;
  rotational_velocity_components.push_back(std::move(rotational_velocity_component));
  e.rotational_velocity_component = &rotational_velocity_components[rotational_velocity_components.size()-1];
  rotational_velocity_component.entity = &e;
}


if(csig & component_signature_starting_direction_component)
{
  StartingDirectionComponent starting_direction_component;
  starting_direction_components.push_back(std::move(starting_direction_component));
  e.starting_direction_component = &starting_direction_components[starting_direction_components.size()-1];
  starting_direction_component.entity = &e;
}


if(csig & component_signature_starting_position_component)
{
  StartingPositionComponent starting_position_component;
  starting_position_components.push_back(std::move(starting_position_component));
  e.starting_position_component = &starting_position_components[starting_position_components.size()-1];
  starting_position_component.entity = &e;
}


if(csig & component_signature_starting_rotational_velocity_component)
{
  StartingRotationalVelocityComponent starting_rotational_velocity_component;
  starting_rotational_velocity_components.push_back(std::move(starting_rotational_velocity_component));
  e.starting_rotational_velocity_component = &starting_rotational_velocity_components[starting_rotational_velocity_components.size()-1];
  starting_rotational_velocity_component.entity = &e;
}


if(csig & component_signature_starting_velocity_component)
{
  StartingVelocityComponent starting_velocity_component;
  starting_velocity_components.push_back(std::move(starting_velocity_component));
  e.starting_velocity_component = &starting_velocity_components[starting_velocity_components.size()-1];
  starting_velocity_component.entity = &e;
}


if(csig & component_signature_velocity_component)
{
  VelocityComponent velocity_component;
  velocity_components.push_back(std::move(velocity_component));
  e.velocity_component = &velocity_components[velocity_components.size()-1];
  velocity_component.entity = &e;
}

//ECS_CONSTRUCT_ADD_C_TO_E_END

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

