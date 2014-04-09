#include "view_component.h"

glm::mat4 ViewComponent::viewMat()
{
  return glm::lookAt(glm::vec3(5,0,20),glm::vec3(0,0,0),glm::vec3(0,1,0));
}

