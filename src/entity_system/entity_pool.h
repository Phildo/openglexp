#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
//ECS_CONSTRUCT_C_INCLUDE_START
#include "components/camera_component.h"
#include "components/geometry_component.h"
#include "components/light_component.h"
#include "components/spacial_component.h"
//ECS_CONSTRUCT_C_INCLUDE_END

#define MAX_ENTITIES 100

typedef long component_signature;
//ECS_CONSTRUCT_C_SIGNATURE_DEF_START
const component_signature component_signature_camera_component = 1;
const component_signature component_signature_geometry_component = 2;
const component_signature component_signature_light_component = 4;
const component_signature component_signature_spacial_component = 8;
//ECS_CONSTRUCT_C_SIGNATURE_DEF_END

class EntityPool
{
  private:
  public:
Entity entities[MAX_ENTITIES]; int num_entities;

//ECS_CONSTRUCT_PUBLIC_C_DECL_START
CameraComponent camera_components[MAX_ENTITIES]; int num_camera_components;
GeometryComponent geometry_components[MAX_ENTITIES]; int num_geometry_components;
LightComponent light_components[MAX_ENTITIES]; int num_light_components;
SpacialComponent spacial_components[MAX_ENTITIES]; int num_spacial_components;
//ECS_CONSTRUCT_PUBLIC_C_DECL_END

    EntityPool();
    ~EntityPool();

    Entity* createEntity(component_signature csig);
    void deleteEntity(Entity* e);
};

#endif

