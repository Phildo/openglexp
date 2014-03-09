#include "geo_component.h"

GeoComponent::GeoComponent()
{
  numVerts = 3;

  modelMatR = glm::mat4(1.0f);
  modelMatA = glm::mat4(1.0f);

  pos[0] = glm::vec3(-5.0f,-5.0f,0.0f);
  pos[1] = glm::vec3( 0.0f, 5.0f,0.0f);
  pos[2] = glm::vec3( 5.0f,-5.0f,0.0f);

  color[0] = glm::vec3(0.2f,0.2f,0.2f);
  color[1] = glm::vec3(1.0f,1.0f,1.0f);
  color[2] = glm::vec3(0.2f,0.2f,0.2f);

  norm[0] = glm::vec3(0.0f,0.0,1.0f);
  norm[1] = glm::vec3(0.0f,0.0,1.0f);
  norm[2] = glm::vec3(0.0f,0.0,1.0f);
}

GeoComponent::~GeoComponent()
{
}

