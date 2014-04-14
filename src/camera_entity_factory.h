#ifndef _CAMERA_ENTITY_FACTORY_H_
#define _CAMERA_ENTITY_FACTORY_H_

#include "entity_system/entity_factory.h"

class EntityPool;

class CameraEntityFactory : public EntityFactory
{
  private:
  public:
    void produce(EntityPool* ep);
};

#endif

