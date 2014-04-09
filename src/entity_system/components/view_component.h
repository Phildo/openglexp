#ifndef _VIEW_COMPONENT_H_
#define _VIEW_COMPONENT_H_

#include "gl_include.h"
class Entity;

class ViewComponent
{
  private:
  public:
    Entity* entity;

    glm::mat4 viewMat();
};

#endif

