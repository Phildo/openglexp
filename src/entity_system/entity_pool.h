#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
//ECS_CONSTRUCT_C_INCLUDE_START
#include "components/direction_component.h"
#include "components/geometry_component.h"
#include "components/hud_component.h"
#include "components/input_component.h"
#include "components/light_component.h"
#include "components/position_component.h"
#include "components/rotational_velocity_component.h"
#include "components/starting_direction_component.h"
#include "components/starting_position_component.h"
#include "components/starting_rotational_velocity_component.h"
#include "components/starting_velocity_component.h"
#include "components/velocity_component.h"
//ECS_CONSTRUCT_C_INCLUDE_END

typedef long component_signature;
//ECS_CONSTRUCT_C_SIGNATURE_DEF_START
const component_signature component_signature_direction_component = 1;
const component_signature component_signature_geometry_component = 2;
const component_signature component_signature_hud_component = 4;
const component_signature component_signature_input_component = 8;
const component_signature component_signature_light_component = 16;
const component_signature component_signature_position_component = 32;
const component_signature component_signature_rotational_velocity_component = 64;
const component_signature component_signature_starting_direction_component = 128;
const component_signature component_signature_starting_position_component = 256;
const component_signature component_signature_starting_rotational_velocity_component = 512;
const component_signature component_signature_starting_velocity_component = 1024;
const component_signature component_signature_velocity_component = 2048;
//ECS_CONSTRUCT_C_SIGNATURE_DEF_END

class EntityPool
{
  private:
  public:
    std::vector<Entity> entities;

//ECS_CONSTRUCT_PUBLIC_C_DECL_START
std::vector<DirectionComponent> direction_components;
std::vector<GeometryComponent> geometry_components;
std::vector<HudComponent> hud_components;
std::vector<InputComponent> input_components;
std::vector<LightComponent> light_components;
std::vector<PositionComponent> position_components;
std::vector<RotationalVelocityComponent> rotational_velocity_components;
std::vector<StartingDirectionComponent> starting_direction_components;
std::vector<StartingPositionComponent> starting_position_components;
std::vector<StartingRotationalVelocityComponent> starting_rotational_velocity_components;
std::vector<StartingVelocityComponent> starting_velocity_components;
std::vector<VelocityComponent> velocity_components;
//ECS_CONSTRUCT_PUBLIC_C_DECL_END

    EntityPool();
    ~EntityPool();

    Entity& createEntity(component_signature csig);
    void deleteEntity(int index);
};

#endif

