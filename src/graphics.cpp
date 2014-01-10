#include "graphics.h"
#include "include.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

void resize(GLFWwindow* window, int width, int height);

const std::string stringFromFile(const char *fileName)
{
  std::string line = "";
  std::string resultString;
  std::ifstream fileStream(fileName, std::ios::in);
  while(getline(fileStream, line))
    resultString += "\n" + line;
  fileStream.close();
  return resultString;
}

Graphics::Graphics(GLFWwindow* win)
{
  window = win;

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

  glClearColor(255,255,255,0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  //cpu Data
  projMat  = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  viewMat  = glm::lookAt(glm::vec3(4,3,3),glm::vec3(0,0,0),glm::vec3(0,1,0));
  modelMat = glm::mat4(1.0f);
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

  //gen Shaders
  GLuint VertexShaderID   = glCreateShader(GL_VERTEX_SHADER);
  GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

  const char *vscp = stringFromFile(V_SHADER_FILE).c_str();
  glShaderSource(VertexShaderID, 1, &vscp, NULL);
  glCompileShader(VertexShaderID);

  const char *fscp = stringFromFile(F_SHADER_FILE).c_str();
  glShaderSource(FragmentShaderID, 1, &fscp, NULL);
  glCompileShader(FragmentShaderID);

  gl_programID = glCreateProgram();
  glAttachShader(gl_programID, VertexShaderID);
  glAttachShader(gl_programID, FragmentShaderID);
  glLinkProgram(gl_programID);

  glDeleteShader(VertexShaderID);
  glDeleteShader(FragmentShaderID);

  //gen IDs
  glGenVertexArrays(1, &gl_vertArrayID);
  glGenBuffers(1, &gl_vertBufferID);
  glGenBuffers(1, &gl_colorBufferID);
  gl_projMatrixID = glGetUniformLocation(gl_programID, "projMat");
  gl_viewMatrixID = glGetUniformLocation(gl_programID, "viewMat");
  gl_modelMatrixID = glGetUniformLocation(gl_programID, "modelMat");

  //populate buffers
  glBindVertexArray(gl_vertArrayID);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, gl_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertBuffData), vertBuffData, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_colorBufferID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colorBuffData), colorBuffData, GL_STATIC_DRAW);

  glUseProgram(gl_programID);
}

void resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void Graphics::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //REMOVE THIS
  modelMat = glm::rotate(modelMat, 1.0f, glm::vec3(0, 1, 0));

  glBindBuffer(GL_ARRAY_BUFFER, gl_vertBufferID);
// attribute 0. No particular reason for 0, but must match the layout in the shader.
// size
// type
// normalized?
// stride
// array buffer offset
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  glBindBuffer(GL_ARRAY_BUFFER, gl_colorBufferID);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  glUniformMatrix4fv(gl_projMatrixID, 1, GL_FALSE, &projMat[0][0]);
  glUniformMatrix4fv(gl_viewMatrixID, 1, GL_FALSE, &viewMat[0][0]);
  glUniformMatrix4fv(gl_modelMatrixID, 1, GL_FALSE, &modelMat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
  glDeleteVertexArrays(1, &gl_vertArrayID);
  glDeleteBuffers(1, &gl_vertBufferID);
  glDeleteBuffers(1, &gl_colorBufferID);
  glDeleteProgram(gl_programID);
}

