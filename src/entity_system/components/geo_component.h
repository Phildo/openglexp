#ifndef _GEO_COMPONENT_H_
#define _GEO_COMPONENT_H_

#define MAX_VERTS 100

#include "gl_include.h"

class GeoComponent
{
  private:
  public:
    GeoComponent();
    ~GeoComponent();

    int entityIndex;

    int numVerts;
    glm::vec3 pos[MAX_VERTS];
    glm::vec3 color[MAX_VERTS];
    glm::vec3 norm[MAX_VERTS];
    glm::mat4 modelMatR;
    glm::mat4 modelMatA;
};

#endif

