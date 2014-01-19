#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include "entity.h"
#include "physics_component.h"
#include "render_component.h"
#define MAX_ENTITIES 100

class EntityPool
{
  private:
    Entity entities[MAX_ENTITIES];
    PhysicsComponent physics[MAX_ENTITIES];
    RenderComponent renders[MAX_ENTITIES];
  public:
    EntityPool();
    ~EntityPool();
};

#endif

