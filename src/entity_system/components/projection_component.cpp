#include "projection_component.h"

ProjectionComponent::ProjectionComponent()
{
  nearPlane = 0.1f;
  farPlane = 100.0f;
  fov = 45.0f;
  var widthToHeight = 2.0f;
}

glm::mat4 ProjectionComponent::projectionMat()
{
  return glm::perspective(fov, widthToHeight, nearPlane, farPlane);
}

