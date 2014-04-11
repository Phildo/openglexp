#include "camera_component.h"
#include "spacial_component.h"

CameraComponent::CameraComponent()
{
  nearPlane = 0.1f;
  farPlane = 100.0f;
  fov = 45.0f;
  var widthToHeight = 2.0f;
}

glm::mat4 CameraComponent::projectionMat()
{
  return glm::perspective(fov, widthToHeight, nearPlane, farPlane);
}

glm::mat4 CameraComponent::viewMat()
{
  return glm::lookAt(entity->spacial_component->pos,entity->spacial_component->dir,glm::vec3(0,1,0));
}

