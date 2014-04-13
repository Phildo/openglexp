#include "camera_component.h"
#include "spacial_component.h"
#include "../entity.h"

#include <glm/gtc/matrix_transform.hpp>

CameraComponent::CameraComponent()
{
  nearPlane = 0.1f;
  farPlane = 100.0f;
  fov = 45.0f;
  aspect = 2.0f;
}

glm::mat4 CameraComponent::projectionMat() const
{
  return glm::perspective(fov, aspect, nearPlane, farPlane);
}

glm::mat4 CameraComponent::viewMat() const
{
  return glm::lookAt(entity->spacial_component->pos,entity->spacial_component->rot,glm::vec3(0,1,0));
}

