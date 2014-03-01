#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
#include "world_component.h"
#include "physics_component.h"

//do not like
typedef long component_signature;
const component_signature ComponentSig_Physics = 1;
const component_signature ComponentSig_World  = 2;

class EntityPool
{
  private:
  public:
    std::vector<Entity>           entities;

    //Logic Components
    std::vector<PhysicsComponent> physicsComponents;

    //Render Components
    std::vector<WorldComponent>  worldComponents;

    EntityPool();
    ~EntityPool();

    Entity& createEntity(component_signature csig);
    void deleteEntity(int index);
};

#endif

