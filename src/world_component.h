#ifndef _WORLD_COMPONENT_H_
#define _WORLD_COMPONENT_H_

#define MAX_VERTS 100

#include "gl_include.h"

class WorldComponent
{
  private:
  public:
    WorldComponent();
    ~WorldComponent();

    int entityIndex;

    int numVerts;
    glm::vec3 posData[MAX_VERTS];
    glm::vec3 colorData[MAX_VERTS];
    glm::mat4 modelMat;
};

#endif

