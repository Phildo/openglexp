#ifndef _ENTITY_FACTORY_H_
#define _ENTITY_FACTORY_H_

class EntityPool;

class EntityFactory
{
  private:
  public:
    virtual ~EntityFactory() {};
    virtual void produce(EntityPool& ep) = 0;
};

#endif

