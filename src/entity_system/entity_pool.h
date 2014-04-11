#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
//ECS_CONSTRUCT_C_INCLUDE_START
#include "components/bilboard_geometry_component.h"
#include "components/camera_component.h"
#include "components/hud_component.h"
#include "components/input_component.h"
#include "components/light_component.h"
#include "components/spacial_component.h"
#include "components/triangle_geometry_component.h"
//ECS_CONSTRUCT_C_INCLUDE_END

#define MAX_ENTITIES = 100

typedef long component_signature;
//ECS_CONSTRUCT_C_SIGNATURE_DEF_START
const component_signature component_signature_bilboard_geometry_component = 1;
const component_signature component_signature_camera_component = 2;
const component_signature component_signature_hud_component = 4;
const component_signature component_signature_input_component = 8;
const component_signature component_signature_light_component = 16;
const component_signature component_signature_spacial_component = 32;
const component_signature component_signature_triangle_geometry_component = 64;
//ECS_CONSTRUCT_C_SIGNATURE_DEF_END

class EntityPool
{
  private:
  public:
Entity entities[MAX_ENTITIES]; int num_entities;

//ECS_CONSTRUCT_PUBLIC_C_DECL_START
BilboardGeometryComponent bilboard_geometry_components[MAX_ENTITIES]; int num_bilboard_geometry_components;
CameraComponent camera_components[MAX_ENTITIES]; int num_camera_components;
HudComponent hud_components[MAX_ENTITIES]; int num_hud_components;
InputComponent input_components[MAX_ENTITIES]; int num_input_components;
LightComponent light_components[MAX_ENTITIES]; int num_light_components;
SpacialComponent spacial_components[MAX_ENTITIES]; int num_spacial_components;
TriangleGeometryComponent triangle_geometry_components[MAX_ENTITIES]; int num_triangle_geometry_components;
//ECS_CONSTRUCT_PUBLIC_C_DECL_END

    EntityPool();
    ~EntityPool();

    Entity* createEntity(component_signature csig);
    void deleteEntity(Entity* e);
};

#endif

