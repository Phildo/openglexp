#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
#include "physics_component.h"
#include "input_planar_component.h"
#include "geo_component.h"
#include "light_component.h"
#include "hud_component.h"

//do not like
typedef long component_signature;
const component_signature ComponentSig_Physics     = 1;
const component_signature ComponentSig_InputPlanar = 2;
const component_signature ComponentSig_Geo         = 4;
const component_signature ComponentSig_Light       = 8;
const component_signature ComponentSig_HUD         = 16;

class EntityPool
{
  private:
  public:
    std::vector<Entity> entities;

    //Logic Components
    std::vector<PhysicsComponent> physicsComponents;
    std::vector<InputPlanarComponent> inputPlanarComponents;

    //Render Components
    std::vector<GeoComponent>    geoComponents;
    std::vector<LightComponent>  lightComponents;
    std::vector<HUDComponent>    HUDComponents;

    EntityPool();
    ~EntityPool();

    Entity& createEntity(component_signature csig);
    void deleteEntity(int index);
};

#endif

