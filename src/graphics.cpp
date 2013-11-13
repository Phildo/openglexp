#include "graphics.h"
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

  GLuint programID = LoadShaders("shader.vs", "shader.fs");

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
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.f, 1.f, -1.f, 1.f, 1.f, -1.f);
  glMatrixMode(GL_MODELVIEW);
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
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(0);

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
  glDeleteBuffers(1, &vertBufferID);
  glDeleteVertexArrays(1, &vertArrayID);
}

