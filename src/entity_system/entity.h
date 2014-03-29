#ifndef _ENTITY_H_
#define _ENTITY_H_

//ENTITY_CONSTRUCT_FORWARD_DECLS_START
class  GeoComponent;
class  HudComponent;
class  InputPlanarComponent;
class  LightComponent;
class  PhysicsComponent;
//ENTITY_CONSTRUCT_FORWARD_DECLS_END

class Entity
{
  private:
  public:
    //ENTITY_CONSTRUCT_PUBLIC_MEMBERS_START
GeoComponent* geo_component;
HudComponent* hud_component;
InputPlanarComponent* input_planar_component;
LightComponent* light_component;
PhysicsComponent* physics_component;
    //ENTITY_CONSTRUCT_PUBLIC_MEMBERS_END

    Entity();
    ~Entity();
};

#endif

