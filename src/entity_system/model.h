#ifndef _MODEL_H_
#define _MODEL_H_

#define MAX_VERTS 72

#include <glm/glm.hpp>
class Entity;

class Model
{
  private:
  public:
    int numVerts;
    glm::vec3 pos[MAX_VERTS];
    glm::vec3 color[MAX_VERTS];
    glm::vec3 norm[MAX_VERTS];
};

#endif

