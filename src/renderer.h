#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "camera.h"
#include "render_component.h"

class Renderer
{
  private:
  public:
    virtual ~Renderer() = 0;
    virtual void render(Camera& c, RenderComponent& rc);
};

#endif

