#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
  private:
  public:
    int geoComponentIndex;
    int lightComponentIndex;
    int physicsComponentIndex;
    int HUDComponentIndex;

    Entity();
    ~Entity();
};

#endif

