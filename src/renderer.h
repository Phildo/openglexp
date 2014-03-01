#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "graphics.h"

class Renderer
{
  private:
  protected:
    Graphics* graphics;
    GLuint loadShader(const char *vs_filename, const char *fs_filename);
  public:
    Renderer(Graphics* g);
    virtual ~Renderer() = 0;
};

#endif

