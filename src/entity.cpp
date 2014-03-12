#include "entity.h"

Entity::Entity() : 
  physicsComponentIndex(-1),
  inputPlanarComponentIndex(-1),
  geoComponentIndex (-1), 
  lightComponentIndex (-1), 
  HUDComponentIndex(-1)
{
}

Entity::~Entity()
{

}

