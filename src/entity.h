#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
  private:
  public:
    int renderComponentIndex;
    int physicsComponentIndex;

    Entity();
    ~Entity();
};

#endif

