#include "hud_component.h"

HUDComponent::HUDComponent()
{
  numVerts = 3;

  pos[0] = glm::vec3(-1.0,-1.0,0.0);
  pos[1] = glm::vec3( -1.0, 0.0,0.0);
  pos[2] = glm::vec3( 1.0,-1.0,0.0);

  color[0] = glm::vec3(0.0,0.0,0.0);
  color[1] = glm::vec3(1.0,1.0,1.0);
  color[2] = glm::vec3(0.0,0.0,0.0);
}

HUDComponent::~HUDComponent()
{
}

