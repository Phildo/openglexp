#ifndef _LIGHT_COMPONENT_H_
#define _LIGHT_COMPONENT_H_

#include "gl_include.h"

class LightComponent
{
  private:
  public:
    LightComponent();
    ~LightComponent();

    int entityIndex;

    glm::vec3 pos;
};

#endif

