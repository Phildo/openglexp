#include "camera.h"

Camera::Camera()
{
  projMat  = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  viewMat  = glm::lookAt(glm::vec3(0,15,15),glm::vec3(0,0,0),glm::vec3(0,1,0));
}

Camera::~Camera()
{

}

