#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

#include "component.h"

class RenderComponent : public Component
{
  private:
    int modelId; // total bs
  public:
    RenderComponent();
    ~RenderComponent();
};

#endif
