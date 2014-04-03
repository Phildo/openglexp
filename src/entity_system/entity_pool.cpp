#include "entity_pool.h"

EntityPool::EntityPool()
{

}

EntityPool::~EntityPool()
{

}

//This is so not thread safe it isn't even funny
Entity* EntityPool::createEntity(component_signature csig)
{
  Entity* e = &entities[num_entities];

//ECS_CONSTRUCT_ADD_C_TO_E_START
if(csig & component_signature_direction_component)
{
  e->direction_component = &direction_components[num_direction_components];
  direction_components[num_direction_components].entity = e;
  num_direction_components++;
}

if(csig & component_signature_geometry_component)
{
  e->geometry_component = &geometry_components[num_geometry_components];
  geometry_components[num_geometry_components].entity = e;
  num_geometry_components++;
}

if(csig & component_signature_hud_component)
{
  e->hud_component = &hud_components[num_hud_components];
  hud_components[num_hud_components].entity = e;
  num_hud_components++;
}

if(csig & component_signature_input_component)
{
  e->input_component = &input_components[num_input_components];
  input_components[num_input_components].entity = e;
  num_input_components++;
}

if(csig & component_signature_light_component)
{
  e->light_component = &light_components[num_light_components];
  light_components[num_light_components].entity = e;
  num_light_components++;
}

if(csig & component_signature_position_component)
{
  e->position_component = &position_components[num_position_components];
  position_components[num_position_components].entity = e;
  num_position_components++;
}

if(csig & component_signature_rotational_velocity_component)
{
  e->rotational_velocity_component = &rotational_velocity_components[num_rotational_velocity_components];
  rotational_velocity_components[num_rotational_velocity_components].entity = e;
  num_rotational_velocity_components++;
}

if(csig & component_signature_starting_direction_component)
{
  e->starting_direction_component = &starting_direction_components[num_starting_direction_components];
  starting_direction_components[num_starting_direction_components].entity = e;
  num_starting_direction_components++;
}

if(csig & component_signature_starting_position_component)
{
  e->starting_position_component = &starting_position_components[num_starting_position_components];
  starting_position_components[num_starting_position_components].entity = e;
  num_starting_position_components++;
}

if(csig & component_signature_starting_rotational_velocity_component)
{
  e->starting_rotational_velocity_component = &starting_rotational_velocity_components[num_starting_rotational_velocity_components];
  starting_rotational_velocity_components[num_starting_rotational_velocity_components].entity = e;
  num_starting_rotational_velocity_components++;
}

if(csig & component_signature_starting_velocity_component)
{
  e->starting_velocity_component = &starting_velocity_components[num_starting_velocity_components];
  starting_velocity_components[num_starting_velocity_components].entity = e;
  num_starting_velocity_components++;
}

if(csig & component_signature_velocity_component)
{
  e->velocity_component = &velocity_components[num_velocity_components];
  velocity_components[num_velocity_components].entity = e;
  num_velocity_components++;
}

//ECS_CONSTRUCT_ADD_C_TO_E_END

  num_entities++;
  return e;
}

//Again- not thread safe at all. I'm a terrible person.
void EntityPool::deleteEntity(Entity* e)
{
  num_entities--;

//ECS_CONSTRUCT_DELETE_C_FROM_E_START
if(e->direction_component)
{
  num_direction_components--;
  direction_components[num_direction_components].entity.direction_component = e->direction_component;
  *e->direction_component = direction_components[num_direction_components];
}

if(e->geometry_component)
{
  num_geometry_components--;
  geometry_components[num_geometry_components].entity.geometry_component = e->geometry_component;
  *e->geometry_component = geometry_components[num_geometry_components];
}

if(e->hud_component)
{
  num_hud_components--;
  hud_components[num_hud_components].entity.hud_component = e->hud_component;
  *e->hud_component = hud_components[num_hud_components];
}

if(e->input_component)
{
  num_input_components--;
  input_components[num_input_components].entity.input_component = e->input_component;
  *e->input_component = input_components[num_input_components];
}

if(e->light_component)
{
  num_light_components--;
  light_components[num_light_components].entity.light_component = e->light_component;
  *e->light_component = light_components[num_light_components];
}

if(e->position_component)
{
  num_position_components--;
  position_components[num_position_components].entity.position_component = e->position_component;
  *e->position_component = position_components[num_position_components];
}

if(e->rotational_velocity_component)
{
  num_rotational_velocity_components--;
  rotational_velocity_components[num_rotational_velocity_components].entity.rotational_velocity_component = e->rotational_velocity_component;
  *e->rotational_velocity_component = rotational_velocity_components[num_rotational_velocity_components];
}

if(e->starting_direction_component)
{
  num_starting_direction_components--;
  starting_direction_components[num_starting_direction_components].entity.starting_direction_component = e->starting_direction_component;
  *e->starting_direction_component = starting_direction_components[num_starting_direction_components];
}

if(e->starting_position_component)
{
  num_starting_position_components--;
  starting_position_components[num_starting_position_components].entity.starting_position_component = e->starting_position_component;
  *e->starting_position_component = starting_position_components[num_starting_position_components];
}

if(e->starting_rotational_velocity_component)
{
  num_starting_rotational_velocity_components--;
  starting_rotational_velocity_components[num_starting_rotational_velocity_components].entity.starting_rotational_velocity_component = e->starting_rotational_velocity_component;
  *e->starting_rotational_velocity_component = starting_rotational_velocity_components[num_starting_rotational_velocity_components];
}

if(e->starting_velocity_component)
{
  num_starting_velocity_components--;
  starting_velocity_components[num_starting_velocity_components].entity.starting_velocity_component = e->starting_velocity_component;
  *e->starting_velocity_component = starting_velocity_components[num_starting_velocity_components];
}

if(e->velocity_component)
{
  num_velocity_components--;
  velocity_components[num_velocity_components].entity.velocity_component = e->velocity_component;
  *e->velocity_component = velocity_components[num_velocity_components];
}

//ECS_CONSTRUCT_DELETE_C_FROM_E_END

//ECS_CONSTRUCT_DELETE_E_START
if(entities[num_entities].direction_component)
  entities[num_entities].direction_component.entity = e;
if(entities[num_entities].geometry_component)
  entities[num_entities].geometry_component.entity = e;
if(entities[num_entities].hud_component)
  entities[num_entities].hud_component.entity = e;
if(entities[num_entities].input_component)
  entities[num_entities].input_component.entity = e;
if(entities[num_entities].light_component)
  entities[num_entities].light_component.entity = e;
if(entities[num_entities].position_component)
  entities[num_entities].position_component.entity = e;
if(entities[num_entities].rotational_velocity_component)
  entities[num_entities].rotational_velocity_component.entity = e;
if(entities[num_entities].starting_direction_component)
  entities[num_entities].starting_direction_component.entity = e;
if(entities[num_entities].starting_position_component)
  entities[num_entities].starting_position_component.entity = e;
if(entities[num_entities].starting_rotational_velocity_component)
  entities[num_entities].starting_rotational_velocity_component.entity = e;
if(entities[num_entities].starting_velocity_component)
  entities[num_entities].starting_velocity_component.entity = e;
if(entities[num_entities].velocity_component)
  entities[num_entities].velocity_component.entity = e;
//ECS_CONSTRUCT_DELETE_E_END

  *e = entities[num_entities];
}

