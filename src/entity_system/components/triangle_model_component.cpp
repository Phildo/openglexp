#include "triangle_model_component.h"

TriangleModelComponent::TriangleModelComponent()
{
  pos[0] = glm::vec3( 5.0f,-5.0f,0.1f);
  pos[1] = glm::vec3( 0.0f, 5.0f,0.1f);
  pos[2] = glm::vec3(-5.0f,-5.0f,0.1f);
  pos[3] = glm::vec3(-5.0f,-5.0f,-0.1f);
  pos[4] = glm::vec3( 0.0f, 5.0f,-0.1f);
  pos[5] = glm::vec3( 5.0f,-5.0f,-0.1f);

  color[0] = glm::vec3(0.2f,0.2f,0.2f);
  color[1] = glm::vec3(1.0f,1.0f,1.0f);
  color[2] = glm::vec3(0.2f,0.2f,0.2f);
  color[3] = glm::vec3(0.2f,0.2f,0.2f);
  color[4] = glm::vec3(1.0f,1.0f,1.0f);
  color[5] = glm::vec3(0.2f,0.2f,0.2f);

  norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  norm[5] = glm::vec3(0.0f,0.0f,-1.0f);
}

