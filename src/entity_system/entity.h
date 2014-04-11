#ifndef _ENTITY_H_
#define _ENTITY_H_

//ECS_CONSTRUCT_C_FORWARD_DECLS_START
class BilboardGeometryComponent;
class CameraComponent;
class HudComponent;
class InputComponent;
class LightComponent;
class SpacialComponent;
class TriangleGeometryComponent;
//ECS_CONSTRUCT_C_FORWARD_DECLS_END

class Entity
{
  private:
  public:
//ECS_CONSTRUCT_PUBLIC_C_MEMBERS_START
BilboardGeometryComponent* bilboard_geometry_component;
CameraComponent* camera_component;
HudComponent* hud_component;
InputComponent* input_component;
LightComponent* light_component;
SpacialComponent* spacial_component;
TriangleGeometryComponent* triangle_geometry_component;
//ECS_CONSTRUCT_PUBLIC_C_MEMBERS_END

    Entity();
    ~Entity();
};

#endif

