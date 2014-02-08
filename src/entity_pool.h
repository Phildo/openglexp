#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include <vector>
#include "entity.h"
#include "render_component.h"
#include "physics_component.h"

#define MAX_ENTITIES 100

class EntityPool
{
  private:
    Vector<Entity>           entities;
    Vector<PhysicsComponent> physicsComponents;
    Vector<RenderComponent>  renderComponents;
  public:
    EntityPool();
    ~EntityPool();

    int createEntity(bool physics, bool render);
    void deleteEntity(int index);
};

#endif

