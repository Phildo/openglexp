#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
#include "render_component.h"
#include "physics_component.h"

#define MAX_ENTITIES 100

typedef long component_signature;
const component_signature ComponentSig_Physics = 1;
const component_signature ComponentSig_Render  = 2;

class EntityPool
{
  private:
    std::vector<Entity>           entities;
    std::vector<PhysicsComponent> physicsComponents;
    std::vector<RenderComponent>  renderComponents;
  public:
    EntityPool();
    ~EntityPool();

    int createEntity(component_signature csig);
    void deleteEntity(int index);
};

#endif

