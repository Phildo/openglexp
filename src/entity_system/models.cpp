#include "models.h"

Models::Models()
{
  models[SCREEN_QUAD_MODEL].numVerts = 6;
  models[SCREEN_QUAD_MODEL].pos[0] = glm::vec3(-1.0,-1.0,0.0);
  models[SCREEN_QUAD_MODEL].pos[1] = glm::vec3( 1.0,-1.0,0.0);
  models[SCREEN_QUAD_MODEL].pos[2] = glm::vec3( 1.0, 1.0,0.0);
  models[SCREEN_QUAD_MODEL].pos[3] = glm::vec3(-1.0,-1.0,0.0);
  models[SCREEN_QUAD_MODEL].pos[4] = glm::vec3( 1.0, 1.0,0.0);
  models[SCREEN_QUAD_MODEL].pos[5] = glm::vec3(-1.0, 1.0,0.0);

  models[TRIANGLE_MODEL].numVerts = 6;
  models[TRIANGLE_MODEL].pos[0] = glm::vec3( 5.0f,-5.0f,-1.8f);
  models[TRIANGLE_MODEL].pos[1] = glm::vec3( 0.0f, 5.0f,-1.8f);
  models[TRIANGLE_MODEL].pos[2] = glm::vec3(-5.0f,-5.0f,-1.8f);
  models[TRIANGLE_MODEL].pos[3] = glm::vec3(-5.0f,-5.0f,-2.2f);
  models[TRIANGLE_MODEL].pos[4] = glm::vec3( 0.0f, 5.0f,-2.2f);
  models[TRIANGLE_MODEL].pos[5] = glm::vec3( 5.0f,-5.0f,-2.2f);
  models[TRIANGLE_MODEL].color[0] = glm::vec3(0.6f,0.6f,0.6f);
  models[TRIANGLE_MODEL].color[1] = glm::vec3(0.6f,0.6f,0.6f);
  models[TRIANGLE_MODEL].color[2] = glm::vec3(0.6f,0.6f,0.6f);
  models[TRIANGLE_MODEL].color[3] = glm::vec3(0.6f,0.6f,0.6f);
  models[TRIANGLE_MODEL].color[4] = glm::vec3(0.6f,0.6f,0.6f);
  models[TRIANGLE_MODEL].color[5] = glm::vec3(0.6f,0.6f,0.6f);
  models[TRIANGLE_MODEL].norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  models[TRIANGLE_MODEL].norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  models[TRIANGLE_MODEL].norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  models[TRIANGLE_MODEL].norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  models[TRIANGLE_MODEL].norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  models[TRIANGLE_MODEL].norm[5] = glm::vec3(0.0f,0.0f,-1.0f);

  models[BILBOARD_MODEL].numVerts = 6;
  models[BILBOARD_MODEL].pos[0] = glm::vec3( 15.0, 10.0,-8.0);
  models[BILBOARD_MODEL].pos[1] = glm::vec3(-15.0, 10.0,-8.0);
  models[BILBOARD_MODEL].pos[2] = glm::vec3(-15.0,-10.0,-8.0);
  models[BILBOARD_MODEL].pos[3] = glm::vec3( 15.0,-10.0,-8.0);
  models[BILBOARD_MODEL].pos[4] = glm::vec3( 15.0, 10.0,-8.0);
  models[BILBOARD_MODEL].pos[5] = glm::vec3(-15.0,-10.0,-8.0);
  models[BILBOARD_MODEL].color[0] = glm::vec3(0.8,0.2,0.2);
  models[BILBOARD_MODEL].color[1] = glm::vec3(0.2,0.2,0.2);
  models[BILBOARD_MODEL].color[2] = glm::vec3(0.2,0.8,0.2);
  models[BILBOARD_MODEL].color[3] = glm::vec3(0.8,0.2,0.2);
  models[BILBOARD_MODEL].color[4] = glm::vec3(0.2,0.8,0.2);
  models[BILBOARD_MODEL].color[5] = glm::vec3(0.2,0.2,0.2);
  models[BILBOARD_MODEL].norm[0] = glm::vec3(0.0,0.0,1.0);
  models[BILBOARD_MODEL].norm[1] = glm::vec3(0.0,0.0,1.0);
  models[BILBOARD_MODEL].norm[2] = glm::vec3(0.0,0.0,1.0);
  models[BILBOARD_MODEL].norm[3] = glm::vec3(0.0,0.0,1.0);
  models[BILBOARD_MODEL].norm[4] = glm::vec3(0.0,0.0,1.0);
  models[BILBOARD_MODEL].norm[5] = glm::vec3(0.0,0.0,1.0);

  models[CUBE_MODEL].numVerts = 6;
  models[CUBE_MODEL].pos[0] = glm::vec3( 5.0f,-5.0f,-1.9f);
  models[CUBE_MODEL].pos[1] = glm::vec3( 0.0f, 5.0f,-1.9f);
  models[CUBE_MODEL].pos[2] = glm::vec3(-5.0f,-5.0f,-1.9f);
  models[CUBE_MODEL].pos[3] = glm::vec3(-5.0f,-5.0f,-2.1f);
  models[CUBE_MODEL].pos[4] = glm::vec3( 0.0f, 5.0f,-2.1f);
  models[CUBE_MODEL].pos[5] = glm::vec3( 5.0f,-5.0f,-2.1f);
  models[CUBE_MODEL].color[0] = glm::vec3(0.2f,0.2f,0.2f);
  models[CUBE_MODEL].color[1] = glm::vec3(1.0f,1.0f,1.0f);
  models[CUBE_MODEL].color[2] = glm::vec3(0.2f,0.2f,0.2f);
  models[CUBE_MODEL].color[3] = glm::vec3(0.2f,0.2f,0.2f);
  models[CUBE_MODEL].color[4] = glm::vec3(1.0f,1.0f,1.0f);
  models[CUBE_MODEL].color[5] = glm::vec3(0.2f,0.2f,0.2f);
  models[CUBE_MODEL].norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  models[CUBE_MODEL].norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  models[CUBE_MODEL].norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  models[CUBE_MODEL].norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  models[CUBE_MODEL].norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  models[CUBE_MODEL].norm[5] = glm::vec3(0.0f,0.0f,-1.0f);
}

