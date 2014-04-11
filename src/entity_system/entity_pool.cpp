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
if(csig & component_signature_bilboard_geometry_component)
{
  e->bilboard_geometry_component = &bilboard_geometry_components[num_bilboard_geometry_components];
  bilboard_geometry_components[num_bilboard_geometry_components].entity = e;
  num_bilboard_geometry_components++;
}

if(csig & component_signature_camera_component)
{
  e->camera_component = &camera_components[num_camera_components];
  camera_components[num_camera_components].entity = e;
  num_camera_components++;
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

if(csig & component_signature_spacial_component)
{
  e->spacial_component = &spacial_components[num_spacial_components];
  spacial_components[num_spacial_components].entity = e;
  num_spacial_components++;
}

if(csig & component_signature_triangle_geometry_component)
{
  e->triangle_geometry_component = &triangle_geometry_components[num_triangle_geometry_components];
  triangle_geometry_components[num_triangle_geometry_components].entity = e;
  num_triangle_geometry_components++;
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
if(e->bilboard_geometry_component)
{
  num_bilboard_geometry_components--;
  bilboard_geometry_components[num_bilboard_geometry_components].entity.bilboard_geometry_component = e->bilboard_geometry_component;
  *e->bilboard_geometry_component = bilboard_geometry_components[num_bilboard_geometry_components];
}

if(e->camera_component)
{
  num_camera_components--;
  camera_components[num_camera_components].entity.camera_component = e->camera_component;
  *e->camera_component = camera_components[num_camera_components];
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

if(e->spacial_component)
{
  num_spacial_components--;
  spacial_components[num_spacial_components].entity.spacial_component = e->spacial_component;
  *e->spacial_component = spacial_components[num_spacial_components];
}

if(e->triangle_geometry_component)
{
  num_triangle_geometry_components--;
  triangle_geometry_components[num_triangle_geometry_components].entity.triangle_geometry_component = e->triangle_geometry_component;
  *e->triangle_geometry_component = triangle_geometry_components[num_triangle_geometry_components];
}

//ECS_CONSTRUCT_DELETE_C_FROM_E_END

//ECS_CONSTRUCT_DELETE_E_START
if(entities[num_entities].bilboard_geometry_component)
  entities[num_entities].bilboard_geometry_component.entity = e;
if(entities[num_entities].camera_component)
  entities[num_entities].camera_component.entity = e;
if(entities[num_entities].hud_component)
  entities[num_entities].hud_component.entity = e;
if(entities[num_entities].input_component)
  entities[num_entities].input_component.entity = e;
if(entities[num_entities].light_component)
  entities[num_entities].light_component.entity = e;
if(entities[num_entities].spacial_component)
  entities[num_entities].spacial_component.entity = e;
if(entities[num_entities].triangle_geometry_component)
  entities[num_entities].triangle_geometry_component.entity = e;
//ECS_CONSTRUCT_DELETE_E_END

  *e = entities[num_entities];
}

