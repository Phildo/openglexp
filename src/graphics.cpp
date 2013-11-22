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
  glColor3d(0.0f,0.0f,0.0f);

  vertArrayID = 0;
  glGenVertexArrays(1, &vertArrayID);
  glBindVertexArray(vertArrayID);

  GLuint programID = LoadShaders(V_SHADER_FILE, F_SHADER_FILE);

  ProjMatrixID = glGetUniformLocation(programID, "ProjMat");
  ViewMatrixID = glGetUniformLocation(programID, "ViewMat");
  ModelMatrixID = glGetUniformLocation(programID, "ModelMat");

  ProjMat  = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  ViewMat  = glm::lookAt(glm::vec3(4,3,3),glm::vec3(0,0,0),glm::vec3(0,1,0));
  ModelMat = glm::mat4(1.0f);

  GLfloat vertBuffData[] = { 
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
  };

  vertBufferID = 0;
  glGenBuffers(1, &vertBufferID);
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertBuffData), vertBuffData, GL_STATIC_DRAW);

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
  glVertexAttribPointer(
          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
          3,                  // size
          GL_FLOAT,           // type
          GL_FALSE,           // normalized?
          0,                  // stride
          (void*)0            // array buffer offset
  );

  glUniformMatrix4fv(ProjMatrixID, 1, GL_FALSE, &ProjMat[0][0]);
  glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMat[0][0]);
  glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(0);

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
  glDeleteBuffers(1, &vertBufferID);
  glDeleteVertexArrays(1, &vertArrayID);
}

