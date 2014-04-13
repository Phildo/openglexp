#ifndef _ENTITY_H_
#define _ENTITY_H_

//ECS_CONSTRUCT_C_FORWARD_DECLS_START
class CameraComponent;
class GeometryComponent;
class LightComponent;
class SpacialComponent;
//ECS_CONSTRUCT_C_FORWARD_DECLS_END

class Entity
{
  private:
  public:
//ECS_CONSTRUCT_PUBLIC_C_MEMBERS_START
CameraComponent* camera_component;
GeometryComponent* geometry_component;
LightComponent* light_component;
SpacialComponent* spacial_component;
//ECS_CONSTRUCT_PUBLIC_C_MEMBERS_END
};

#endif

