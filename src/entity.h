#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
  private:
  public:
    int physicsComponentIndex;
    int inputPlanarComponentIndex;
    int geoComponentIndex;
    int lightComponentIndex;
    int HUDComponentIndex;

    Entity();
    ~Entity();
};

#endif

