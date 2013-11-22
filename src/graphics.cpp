#include "graphics.h"
#include "include.h"
#include "shader.h"

void resize(GLFWwindow* window, int width, int height);

Graphics::Graphics(GLFWwindow* win)
{
  window = win;

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

  glClearColor(255,255,255,0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  //cpu Data
  ProjMat  = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  ViewMat  = glm::lookAt(glm::vec3(4,3,3),glm::vec3(0,0,0),glm::vec3(0,1,0));
  ModelMat = glm::mat4(1.0f);
  GLfloat vertBuffData[] = { 
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
  };
  GLfloat colorBuffData[] = {
    0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.0f,
  };

  //gen IDs
  programID = LoadShaders(V_SHADER_FILE, F_SHADER_FILE);
  glGenVertexArrays(1, &vertArrayID); //I DONT UNDERSTAND
  glBindVertexArray(vertArrayID); //THESE TWO LINES
  glGenBuffers(1, &vertBufferID);
  glGenBuffers(1, &colorBufferID);
  ProjMatrixID = glGetUniformLocation(programID, "ProjMat");
  ViewMatrixID = glGetUniformLocation(programID, "ViewMat");
  ModelMatrixID = glGetUniformLocation(programID, "ModelMat");

  //populate buffers
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertBuffData), vertBuffData, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, colorBufferID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colorBuffData), colorBuffData, GL_STATIC_DRAW);

  glUseProgram(programID);
}

void resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void Graphics::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
// attribute 0. No particular reason for 0, but must match the layout in the shader.
// size
// type
// normalized?
// stride
// array buffer offset
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colorBufferID);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  glUniformMatrix4fv(ProjMatrixID, 1, GL_FALSE, &ProjMat[0][0]);
  glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMat[0][0]);
  glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
  glDeleteBuffers(1, &vertBufferID);
  glDeleteBuffers(1, &colorBufferID);
  glDeleteProgram(programID);
  glDeleteVertexArrays(1, &vertArrayID);
}

