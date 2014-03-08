#include "entity.h"

Entity::Entity() : 
  geoComponentIndex (-1), 
  lightComponentIndex (-1), 
  physicsComponentIndex(-1),
  HUDComponentIndex(-1)
{
}

Entity::~Entity()
{

}

