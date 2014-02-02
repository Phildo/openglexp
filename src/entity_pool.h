#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include "fixed_vector.h"
#include "entity.h"
#include "render_component.h"
#include "physics_component.h"

#define MAX_ENTITIES 100

class EntityPool
{
  private:
    FixedVector<Entity,           MAX_ENTITIES> entities;
    FixedVector<PhysicsComponent, MAX_ENTITIES> physicsComponents;
    FixedVector<RenderComponent,  MAX_ENTITIES> renderComponents;
  public:
    EntityPool();
    ~EntityPool();

    int createEntity(bool physics, bool render);
    void deleteEntity(int index);
};

#endif

