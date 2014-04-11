#include "models.h"

Models::Models()
{
  triangle.numVerts 6;
  triangle.pos[0] = glm::vec3( 5.0f,-5.0f,0.1f);
  triangle.pos[1] = glm::vec3( 0.0f, 5.0f,0.1f);
  triangle.pos[2] = glm::vec3(-5.0f,-5.0f,0.1f);
  triangle.pos[3] = glm::vec3(-5.0f,-5.0f,-0.1f);
  triangle.pos[4] = glm::vec3( 0.0f, 5.0f,-0.1f);
  triangle.pos[5] = glm::vec3( 5.0f,-5.0f,-0.1f);
  triangle.color[0] = glm::vec3(0.2f,0.2f,0.2f);
  triangle.color[1] = glm::vec3(1.0f,1.0f,1.0f);
  triangle.color[2] = glm::vec3(0.2f,0.2f,0.2f);
  triangle.color[3] = glm::vec3(0.2f,0.2f,0.2f);
  triangle.color[4] = glm::vec3(1.0f,1.0f,1.0f);
  triangle.color[5] = glm::vec3(0.2f,0.2f,0.2f);
  triangle.norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  triangle.norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  triangle.norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  triangle.norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  triangle.norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  triangle.norm[5] = glm::vec3(0.0f,0.0f,-1.0f);

  bilboard.numVerts 6;
  bilboard.pos[0] = glm::vec3( 15.0, 10.0,-8.0);
  bilboard.pos[1] = glm::vec3(-15.0, 10.0,-8.0);
  bilboard.pos[2] = glm::vec3(-15.0,-10.0,-8.0);
  bilboard.pos[3] = glm::vec3( 15.0,-10.0,-8.0);
  bilboard.pos[4] = glm::vec3( 15.0, 10.0,-8.0);
  bilboard.pos[5] = glm::vec3(-15.0,-10.0,-8.0);
  bilboard.color[0] = glm::vec3(0.8,0.2,0.2);
  bilboard.color[1] = glm::vec3(0.2,0.2,0.2);
  bilboard.color[2] = glm::vec3(0.2,0.8,0.2);
  bilboard.color[3] = glm::vec3(0.8,0.2,0.2);
  bilboard.color[4] = glm::vec3(0.2,0.8,0.2);
  bilboard.color[5] = glm::vec3(0.2,0.2,0.2);
  bilboard.norm[0] = glm::vec3(0.0,0.0,1.0);
  bilboard.norm[1] = glm::vec3(0.0,0.0,1.0);
  bilboard.norm[2] = glm::vec3(0.0,0.0,1.0);
  bilboard.norm[3] = glm::vec3(0.0,0.0,1.0);
  bilboard.norm[4] = glm::vec3(0.0,0.0,1.0);
  bilboard.norm[5] = glm::vec3(0.0,0.0,1.0);
}

