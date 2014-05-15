#include "entity_pool.h"

EntityPool::EntityPool()
{
num_entities = 0;
//ECS_CONSTRUCT_ZERO_COMPONENT_COUNTS_START
num_camera_components = 0;
num_light_components = 0;
num_spacial_components = 0;
num_geometry_bilboard_model_components = 0;
num_geometry_cube_model_components = 0;
num_geometry_inv_cube_model_components = 0;
num_geometry_light_cube_model_components = 0;
num_geometry_screen_quad_model_components = 0;
num_geometry_triangle_model_components = 0;
//ECS_CONSTRUCT_ZERO_COMPONENT_COUNTS_END
}

EntityPool::~EntityPool()
{

}

//This is so not thread safe it isn't even funny
Entity* EntityPool::createEntity(component_signature csig)
{
  Entity* e = &entities[num_entities];

//ECS_CONSTRUCT_ADD_C_TO_E_START
if(csig & component_signature_camera_component)
{
  e->camera_component = &camera_components[num_camera_components];
  camera_components[num_camera_components].entity = e;
  num_camera_components++;
}
else e->camera_component = NULL;

if(csig & component_signature_light_component)
{
  e->light_component = &light_components[num_light_components];
  light_components[num_light_components].entity = e;
  num_light_components++;
}
else e->light_component = NULL;

if(csig & component_signature_spacial_component)
{
  e->spacial_component = &spacial_components[num_spacial_components];
  spacial_components[num_spacial_components].entity = e;
  num_spacial_components++;
}
else e->spacial_component = NULL;

if(csig & component_signature_geometry_bilboard_model)
{
  e->geometry_component = &geometry_bilboard_model_components[num_geometry_bilboard_model_components];
  geometry_bilboard_model_components[num_geometry_bilboard_model_components].entity = e;
  num_geometry_bilboard_model_components++;
}
else if(csig & component_signature_geometry_cube_model)
{
  e->geometry_component = &geometry_cube_model_components[num_geometry_cube_model_components];
  geometry_cube_model_components[num_geometry_cube_model_components].entity = e;
  num_geometry_cube_model_components++;
}
else if(csig & component_signature_geometry_inv_cube_model)
{
  e->geometry_component = &geometry_inv_cube_model_components[num_geometry_inv_cube_model_components];
  geometry_inv_cube_model_components[num_geometry_inv_cube_model_components].entity = e;
  num_geometry_inv_cube_model_components++;
}
else if(csig & component_signature_geometry_light_cube_model)
{
  e->geometry_component = &geometry_light_cube_model_components[num_geometry_light_cube_model_components];
  geometry_light_cube_model_components[num_geometry_light_cube_model_components].entity = e;
  num_geometry_light_cube_model_components++;
}
else if(csig & component_signature_geometry_screen_quad_model)
{
  e->geometry_component = &geometry_screen_quad_model_components[num_geometry_screen_quad_model_components];
  geometry_screen_quad_model_components[num_geometry_screen_quad_model_components].entity = e;
  num_geometry_screen_quad_model_components++;
}
else if(csig & component_signature_geometry_triangle_model)
{
  e->geometry_component = &geometry_triangle_model_components[num_geometry_triangle_model_components];
  geometry_triangle_model_components[num_geometry_triangle_model_components].entity = e;
  num_geometry_triangle_model_components++;
}
else e->geometry_component = NULL;
//ECS_CONSTRUCT_ADD_C_TO_E_END

  num_entities++;
  return e;
}

//Again- not thread safe at all. I'm a terrible person.
void EntityPool::deleteEntity(Entity* e)
{
  num_entities--;

//ECS_CONSTRUCT_DELETE_C_FROM_E_START
if(e->camera_component)
{
  num_camera_components--;
  camera_components[num_camera_components].entity->camera_component = e->camera_component;
  *e->camera_component = camera_components[num_camera_components];
}

if(e->light_component)
{
  num_light_components--;
  light_components[num_light_components].entity->light_component = e->light_component;
  *e->light_component = light_components[num_light_components];
}

if(e->spacial_component)
{
  num_spacial_components--;
  spacial_components[num_spacial_components].entity->spacial_component = e->spacial_component;
  *e->spacial_component = spacial_components[num_spacial_components];
}

if(e->geometry_component)
{
if(e->geometry_component > &geometry_bilboard_model_components[0] && e->geometry_component < (&geometry_bilboard_model_components[0]+MAX_ENTITIES))
{
  num_geometry_bilboard_model_components--;
  geometry_bilboard_model_components[num_geometry_bilboard_model_components].entity->geometry_component = e->geometry_component;
  *e->geometry_component = geometry_bilboard_model_components[num_geometry_bilboard_model_components];
}

if(e->geometry_component > &geometry_cube_model_components[0] && e->geometry_component < (&geometry_cube_model_components[0]+MAX_ENTITIES))
{
  num_geometry_cube_model_components--;
  geometry_cube_model_components[num_geometry_cube_model_components].entity->geometry_component = e->geometry_component;
  *e->geometry_component = geometry_cube_model_components[num_geometry_cube_model_components];
}

if(e->geometry_component > &geometry_inv_cube_model_components[0] && e->geometry_component < (&geometry_inv_cube_model_components[0]+MAX_ENTITIES))
{
  num_geometry_inv_cube_model_components--;
  geometry_inv_cube_model_components[num_geometry_inv_cube_model_components].entity->geometry_component = e->geometry_component;
  *e->geometry_component = geometry_inv_cube_model_components[num_geometry_inv_cube_model_components];
}

if(e->geometry_component > &geometry_light_cube_model_components[0] && e->geometry_component < (&geometry_light_cube_model_components[0]+MAX_ENTITIES))
{
  num_geometry_light_cube_model_components--;
  geometry_light_cube_model_components[num_geometry_light_cube_model_components].entity->geometry_component = e->geometry_component;
  *e->geometry_component = geometry_light_cube_model_components[num_geometry_light_cube_model_components];
}

if(e->geometry_component > &geometry_screen_quad_model_components[0] && e->geometry_component < (&geometry_screen_quad_model_components[0]+MAX_ENTITIES))
{
  num_geometry_screen_quad_model_components--;
  geometry_screen_quad_model_components[num_geometry_screen_quad_model_components].entity->geometry_component = e->geometry_component;
  *e->geometry_component = geometry_screen_quad_model_components[num_geometry_screen_quad_model_components];
}

if(e->geometry_component > &geometry_triangle_model_components[0] && e->geometry_component < (&geometry_triangle_model_components[0]+MAX_ENTITIES))
{
  num_geometry_triangle_model_components--;
  geometry_triangle_model_components[num_geometry_triangle_model_components].entity->geometry_component = e->geometry_component;
  *e->geometry_component = geometry_triangle_model_components[num_geometry_triangle_model_components];
}

}

//ECS_CONSTRUCT_DELETE_C_FROM_E_END

//ECS_CONSTRUCT_DELETE_E_START
if(entities[num_entities].camera_component)
  entities[num_entities].camera_component->entity = e;
if(entities[num_entities].geometry_component)
  entities[num_entities].geometry_component->entity = e;
if(entities[num_entities].light_component)
  entities[num_entities].light_component->entity = e;
if(entities[num_entities].spacial_component)
  entities[num_entities].spacial_component->entity = e;
//ECS_CONSTRUCT_DELETE_E_END

  *e = entities[num_entities];
}

