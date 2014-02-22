#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "camera.h"
#include "render_component.h"

class Renderer
{
  private:
  public:
    virtual ~Renderer() {};
    virtual void render(const Camera& c, const RenderComponent& rc) const = 0;
};

#endif

