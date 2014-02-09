#include "render_component.h"

RenderComponent::RenderComponent(): modelMat(1.0);
{
  numVerts = 3;

  posData[0] = glm::vec3(-1.0,-1.0,0.0);
  posData[1] = glm::vec3( 0.0, 1.0,0.0);
  posData[2] = glm::vec3( 1.0,-1.0,0.0);

  colorData[0] = glm::vec3(0.0,0.0,0.0);
  colorData[1] = glm::vec3(1.0,1.0,1.0);
  colorData[2] = glm::vec3(0.0,0.0,0.0);
}

RenderComponent::~RenderComponent()
{
}

