#include "geo_component.h"

GeoComponent::GeoComponent(): modelMat(1.0f)
{
  numVerts = 3;

  modelMat = glm::mat4(1.0f);

  posData[0] = glm::vec3(-5.0f,-5.0f,0.0f);
  posData[1] = glm::vec3( 0.0f, 5.0f,0.0f);
  posData[2] = glm::vec3( 5.0f,-5.0f,0.0f);

  colorData[0] = glm::vec3(0.2f,0.2f,0.2f);
  colorData[1] = glm::vec3(1.0f,1.0f,1.0f);
  colorData[2] = glm::vec3(0.2f,0.2f,0.2f);

  normData[0] = glm::vec3(0.0f,0.0,1.0f);
  normData[1] = glm::vec3(0.0f,0.0,1.0f);
  normData[2] = glm::vec3(0.0f,0.0,1.0f);
}

GeoComponent::~GeoComponent()
{
}

