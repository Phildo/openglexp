#ifndef _ENTITY_POOL_H_
#define _ENTITY_POOL_H_

#include "fixed_vector.h"
#include "entity.h"
#include "render_component.h"

#define MAX_ENTITIES 100

class EntityFactory;

class EntityPool
{
  private:
    FixedVector<Entity,          MAX_ENTITIES> entities;
    FixedVector<RenderComponent, MAX_ENTITIES> render_comps;
  public:
    EntityPool();
    ~EntityPool();
};

#endif

