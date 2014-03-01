#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
#include "physics_component.h"
#include "world_component.h"
#include "hud_component.h"

//do not like
typedef long component_signature;
const component_signature ComponentSig_Physics = 1;
const component_signature ComponentSig_World   = 2;
const component_signature ComponentSig_HUD     = 4;

class EntityPool
{
  private:
  public:
    std::vector<Entity>           entities;

    //Logic Components
    std::vector<PhysicsComponent> physicsComponents;

    //Render Components
    std::vector<WorldComponent>  worldComponents;
    std::vector<HUDComponent>    HUDComponents;

    EntityPool();
    ~EntityPool();

    Entity& createEntity(component_signature csig);
    void deleteEntity(int index);
};

#endif

