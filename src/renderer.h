#ifndef _RENDERER_H_
#define _RENDERER_H_

class Renderer
{
  private:
  protected:
    GLuint loadShader(const char *vs_filename, const char *fs_filename);
  public:
    Renderer();
    virtual ~Renderer() = 0;
};

#endif

