#ifndef _ENTITY_H_
#define _ENTITY_H_

//ECS_CONSTRUCT_C_FORWARD_DECLS_START
class DirectionComponent;
class GeometryComponent;
class HudComponent;
class InputComponent;
class LightComponent;
class PositionComponent;
class RotationalVelocityComponent;
class StartingDirectionComponent;
class StartingPositionComponent;
class StartingRotationalVelocityComponent;
class StartingVelocityComponent;
class VelocityComponent;
//ECS_CONSTRUCT_C_FORWARD_DECLS_END

class Entity
{
  private:
  public:
//ECS_CONSTRUCT_PUBLIC_C_MEMBERS_START
DirectionComponent* direction_component;
GeometryComponent* geometry_component;
HudComponent* hud_component;
InputComponent* input_component;
LightComponent* light_component;
PositionComponent* position_component;
RotationalVelocityComponent* rotational_velocity_component;
StartingDirectionComponent* starting_direction_component;
StartingPositionComponent* starting_position_component;
StartingRotationalVelocityComponent* starting_rotational_velocity_component;
StartingVelocityComponent* starting_velocity_component;
VelocityComponent* velocity_component;
//ECS_CONSTRUCT_PUBLIC_C_MEMBERS_END

    Entity();
    ~Entity();
};

#endif

