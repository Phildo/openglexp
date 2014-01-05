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
  ProjMat  = glm::mat4(1.0f);//glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
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
  glGenVertexArrays(1, &vertArrayID);
  glGenBuffers(1, &vertBufferID);
  glGenBuffers(1, &colorBufferID);
  ProjMatrixID = glGetUniformLocation(programID, "ProjMat");
  ViewMatrixID = glGetUniformLocation(programID, "ViewMat");
  ModelMatrixID = glGetUniformLocation(programID, "ModelMat");

  //populate buffers
  glBindVertexArray(vertArrayID);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
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


  //REMOVE THIS
  ModelMat = glm::rotate(ModelMat, 1.0f, glm::vec3(0, 1, 0));




  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
// attribute 0. No particular reason for 0, but must match the layout in the shader.
// size
// type
// normalized?
// stride
// array buffer offset
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  glBindBuffer(GL_ARRAY_BUFFER, colorBufferID);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  glUniformMatrix4fv(ProjMatrixID, 1, GL_FALSE, &ProjMat[0][0]);
  glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMat[0][0]);
  glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
  glDeleteVertexArrays(1, &vertArrayID);
  glDeleteBuffers(1, &vertBufferID);
  glDeleteBuffers(1, &colorBufferID);
  glDeleteProgram(programID);
}

