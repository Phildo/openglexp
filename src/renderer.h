#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "camera.h"
#include "render_component.h"

class Renderer
{
  private:
  public:
    virtual ~Renderer() {};
    virtual void render(Camera& c, RenderComponent& rc) = 0;
};

#endif

