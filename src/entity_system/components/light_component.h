#ifndef _LIGHT_COMPONENT_H_
#define _LIGHT_COMPONENT_H_

class Entity;

class LightComponent
{
  private:
  public:
    Entity* entity;
    
    float intensity;
};

#endif

