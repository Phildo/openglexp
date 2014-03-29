#ifndef _HUD_COMPONENT_H_
#define _HUD_COMPONENT_H_

#include <glm/glm.hpp>
#define MAX_HUD_VERTS 20

class HudComponent
{
  private:
  public:
    int entityIndex;

    int numVerts;
    glm::vec3 pos[MAX_HUD_VERTS];
    glm::vec3 color[MAX_HUD_VERTS];
};

#endif

