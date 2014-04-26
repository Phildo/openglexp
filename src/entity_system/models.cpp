#include "models.h"

Model Models::models[MAX_MODELS];

void Models::defineModels()
{
  Models::models[SCREEN_QUAD_MODEL].numVerts = 6;
  Models::models[SCREEN_QUAD_MODEL].pos[0] = glm::vec3(-1.0,-1.0,0.0);
  Models::models[SCREEN_QUAD_MODEL].pos[1] = glm::vec3( 1.0,-1.0,0.0);
  Models::models[SCREEN_QUAD_MODEL].pos[2] = glm::vec3( 1.0, 1.0,0.0);
  Models::models[SCREEN_QUAD_MODEL].pos[3] = glm::vec3(-1.0,-1.0,0.0);
  Models::models[SCREEN_QUAD_MODEL].pos[4] = glm::vec3( 1.0, 1.0,0.0);
  Models::models[SCREEN_QUAD_MODEL].pos[5] = glm::vec3(-1.0, 1.0,0.0);

  Models::models[TRIANGLE_MODEL].numVerts = 6;
  Models::models[TRIANGLE_MODEL].pos[0] = glm::vec3( 5.0f,-5.0f,-1.9f);
  Models::models[TRIANGLE_MODEL].pos[1] = glm::vec3( 0.0f, 5.0f,-1.9f);
  Models::models[TRIANGLE_MODEL].pos[2] = glm::vec3(-5.0f,-5.0f,-1.9f);
  Models::models[TRIANGLE_MODEL].pos[3] = glm::vec3(-5.0f,-5.0f,-2.1f);
  Models::models[TRIANGLE_MODEL].pos[4] = glm::vec3( 0.0f, 5.0f,-2.1f);
  Models::models[TRIANGLE_MODEL].pos[5] = glm::vec3( 5.0f,-5.0f,-2.1f);
  Models::models[TRIANGLE_MODEL].color[0] = glm::vec3(0.6f,0.6f,0.6f);
  Models::models[TRIANGLE_MODEL].color[1] = glm::vec3(0.6f,0.6f,0.6f);
  Models::models[TRIANGLE_MODEL].color[2] = glm::vec3(0.6f,0.6f,0.6f);
  Models::models[TRIANGLE_MODEL].color[3] = glm::vec3(0.6f,0.6f,0.6f);
  Models::models[TRIANGLE_MODEL].color[4] = glm::vec3(0.6f,0.6f,0.6f);
  Models::models[TRIANGLE_MODEL].color[5] = glm::vec3(0.6f,0.6f,0.6f);
  Models::models[TRIANGLE_MODEL].norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  Models::models[TRIANGLE_MODEL].norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  Models::models[TRIANGLE_MODEL].norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  Models::models[TRIANGLE_MODEL].norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  Models::models[TRIANGLE_MODEL].norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  Models::models[TRIANGLE_MODEL].norm[5] = glm::vec3(0.0f,0.0f,-1.0f);

  Models::models[BILBOARD_MODEL].numVerts = 6;
  Models::models[BILBOARD_MODEL].pos[0] = glm::vec3( 15.0, 10.0,-8.0);
  Models::models[BILBOARD_MODEL].pos[1] = glm::vec3(-15.0, 10.0,-8.0);
  Models::models[BILBOARD_MODEL].pos[2] = glm::vec3(-15.0,-10.0,-8.0);
  Models::models[BILBOARD_MODEL].pos[3] = glm::vec3( 15.0,-10.0,-8.0);
  Models::models[BILBOARD_MODEL].pos[4] = glm::vec3( 15.0, 10.0,-8.0);
  Models::models[BILBOARD_MODEL].pos[5] = glm::vec3(-15.0,-10.0,-8.0);
  Models::models[BILBOARD_MODEL].color[0] = glm::vec3(0.8,0.2,0.2);
  Models::models[BILBOARD_MODEL].color[1] = glm::vec3(0.2,0.2,0.2);
  Models::models[BILBOARD_MODEL].color[2] = glm::vec3(0.2,0.8,0.2);
  Models::models[BILBOARD_MODEL].color[3] = glm::vec3(0.8,0.2,0.2);
  Models::models[BILBOARD_MODEL].color[4] = glm::vec3(0.2,0.8,0.2);
  Models::models[BILBOARD_MODEL].color[5] = glm::vec3(0.2,0.2,0.2);
  Models::models[BILBOARD_MODEL].norm[0] = glm::vec3(0.0,0.0,1.0);
  Models::models[BILBOARD_MODEL].norm[1] = glm::vec3(0.0,0.0,1.0);
  Models::models[BILBOARD_MODEL].norm[2] = glm::vec3(0.0,0.0,1.0);
  Models::models[BILBOARD_MODEL].norm[3] = glm::vec3(0.0,0.0,1.0);
  Models::models[BILBOARD_MODEL].norm[4] = glm::vec3(0.0,0.0,1.0);
  Models::models[BILBOARD_MODEL].norm[5] = glm::vec3(0.0,0.0,1.0);

  Models::models[CUBE_MODEL].numVerts = 6;
  Models::models[CUBE_MODEL].pos[0] = glm::vec3( 5.0f,-5.0f,-1.9f);
  Models::models[CUBE_MODEL].pos[1] = glm::vec3( 0.0f, 5.0f,-1.9f);
  Models::models[CUBE_MODEL].pos[2] = glm::vec3(-5.0f,-5.0f,-1.9f);
  Models::models[CUBE_MODEL].pos[3] = glm::vec3(-5.0f,-5.0f,-2.1f);
  Models::models[CUBE_MODEL].pos[4] = glm::vec3( 0.0f, 5.0f,-2.1f);
  Models::models[CUBE_MODEL].pos[5] = glm::vec3( 5.0f,-5.0f,-2.1f);
  Models::models[CUBE_MODEL].color[0] = glm::vec3(0.2f,0.2f,0.2f);
  Models::models[CUBE_MODEL].color[1] = glm::vec3(1.0f,1.0f,1.0f);
  Models::models[CUBE_MODEL].color[2] = glm::vec3(0.2f,0.2f,0.2f);
  Models::models[CUBE_MODEL].color[3] = glm::vec3(0.2f,0.2f,0.2f);
  Models::models[CUBE_MODEL].color[4] = glm::vec3(1.0f,1.0f,1.0f);
  Models::models[CUBE_MODEL].color[5] = glm::vec3(0.2f,0.2f,0.2f);
  Models::models[CUBE_MODEL].norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  Models::models[CUBE_MODEL].norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  Models::models[CUBE_MODEL].norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  Models::models[CUBE_MODEL].norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  Models::models[CUBE_MODEL].norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  Models::models[CUBE_MODEL].norm[5] = glm::vec3(0.0f,0.0f,-1.0f);
}

