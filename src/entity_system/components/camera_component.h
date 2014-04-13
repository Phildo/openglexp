#ifndef _CAMERA_COMPONENT_H_
#define _CAMERA_COMPONENT_H_

#include <glm/glm.hpp>
class Entity;

class CameraComponent
{
  private:
  public:
    CameraComponent();
    Entity* entity;

    float nearPlane;
    float farPlane;
    float fov;
    float aspect;

    glm::mat4 projectionMat() const;
    glm::mat4 viewMat() const;
};

#endif

