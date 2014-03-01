#include "world_component.h"

WorldComponent::WorldComponent(): modelMat(1.0)
{
  numVerts = 3;

  modelMat = glm::mat4(1.0);

  posData[0] = glm::vec3(-5.0,-5.0,0.0);
  posData[1] = glm::vec3( 0.0, 5.0,0.0);
  posData[2] = glm::vec3( 5.0,-5.0,0.0);

  colorData[0] = glm::vec3(0.2,0.2,0.2);
  colorData[1] = glm::vec3(1.0,1.0,1.0);
  colorData[2] = glm::vec3(0.2,0.2,0.2);
}

WorldComponent::~WorldComponent()
{
}

