#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

#define MAX_VERTS 100

struct Vert
{
  float x;
  float y;
  float z;
  float w;
  Vert() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
  Vert(float xx, float yy, float zz, float ww = 1.0f) : x(xx), y(yy), z(zz), w(ww) {}
};

class RenderComponent
{
  private:
    Vert verts[MAX_VERTS];
    int numVerts;
  public:
    int entityIndex;
    RenderComponent();
    ~RenderComponent();
};

#endif

