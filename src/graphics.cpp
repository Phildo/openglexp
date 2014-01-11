#include "graphics.h"
#include "include.h"
#include "utils.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stdlib.h>

#define WIDTH 64
#define LENGTH 64

void resize(GLFWwindow* window, int width, int height);

GLuint loadShader(const char *vs_filename, const char *fs_filename)
{
  GLuint gl_programID;
  GLuint gl_vsID = glCreateShader(GL_VERTEX_SHADER);
  GLuint gl_fsID = glCreateShader(GL_FRAGMENT_SHADER);

  std::string fileContents;
  FLATUtils::stringFromFile(vs_filename, fileContents);
  const char *vscp = fileContents.c_str();
  glShaderSource(gl_vsID, 1, &vscp, NULL);
  glCompileShader(gl_vsID);

  FLATUtils::stringFromFile(fs_filename, fileContents);
  const char *fscp = fileContents.c_str();
  glShaderSource(gl_fsID, 1, &fscp, NULL);
  glCompileShader(gl_fsID);

  gl_programID = glCreateProgram();
  glAttachShader(gl_programID, gl_vsID);
  glAttachShader(gl_programID, gl_fsID);
  glLinkProgram(gl_programID);

  glDeleteShader(gl_vsID);
  glDeleteShader(gl_fsID);

  return gl_programID;
}

struct pt
{
  GLfloat x,y,z;
};

struct tri
{
  pt p0,p1,p2;
};

float randf()
{
  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void genBumpyPlane(int widthx, int lengthz, tri* verts, tri* colors)
{
  pt p0,p1,p2,p3;
  pt c0,c1,c2,c3;
  tri t;

  for(int x = 0; x < widthx; x++)
  {
    for(int z = 0; z < lengthz; z++)
    {
      p0.x = ((x+0)* 1.0f)+(randf()-0.5f)-(widthx/2.0f);
      p0.y =               (randf()-0.5f);
      p0.z = ((z+0)*-1.0f)+(randf()-0.5f)+(lengthz/2.0f);
      c0.x = (randf()/2.0f+0.5f);
      c0.y = (randf()/2.0f+0.5f);
      c0.z = (randf()/2.0f+0.5f);

      p1.x = ((x+0)* 1.0f)+(randf()-0.5f)-(widthx/2.0f);
      p1.y =               (randf()-0.5f);
      p1.z = ((z+1)*-1.0f)+(randf()-0.5f)+(lengthz/2.0f);
      c1.x = (randf()/2.0f+0.5f);
      c1.y = (randf()/2.0f+0.5f);
      c1.z = (randf()/2.0f+0.5f);

      p2.x = ((x+1)* 1.0f)+(randf()-0.5f)-(widthx/2.0f);
      p2.y =               (randf()-0.5f);
      p2.z = ((z+1)*-1.0f)+(randf()-0.5f)+(lengthz/2.0f);
      c2.x = (randf()/2.0f+0.5f);
      c2.y = (randf()/2.0f+0.5f);
      c2.z = (randf()/2.0f+0.5f);

      p3.x = ((x+1)* 1.0f)+(randf()-0.5f)-(widthx/2.0f);
      p3.y =               (randf()-0.5f);
      p3.z = ((z+0)*-1.0f)+(randf()-0.5f)+(lengthz/2.0f);
      c3.x = (randf()/2.0f+0.5f);
      c3.y = (randf()/2.0f+0.5f);
      c3.z = (randf()/2.0f+0.5f);

/*
      std::cout << p0.x << "," << p0.y << "," << p0.z << std::endl;
      std::cout << p1.x << "," << p1.y << "," << p1.z << std::endl;
      std::cout << p2.x << "," << p2.y << "," << p2.z << std::endl;
      std::cout << p3.x << "," << p3.y << "," << p3.z << std::endl;

      std::cout << std::endl;

      std::cout << c0.x << "," << c0.y << "," << c0.z << std::endl;
      std::cout << c1.x << "," << c1.y << "," << c1.z << std::endl;
      std::cout << c2.x << "," << c2.y << "," << c2.z << std::endl;
      std::cout << c3.x << "," << c3.y << "," << c3.z << std::endl;
*/

      t.p0 = p0;
      t.p1 = p1;
      t.p2 = p2;
      verts[2*((x*lengthz)+z)+0] = t;
      t.p0 = c0;
      t.p1 = c1;
      t.p2 = c2;
      colors[2*((x*lengthz)+z)+0] = t;

      t.p0 = p2;
      t.p1 = p3;
      t.p2 = p0;
      verts[2*((x*lengthz)+z)+1] = t;
      t.p0 = c2;
      t.p1 = c3;
      t.p2 = c0;
      colors[2*((x*lengthz)+z)+1] = t;
    }
  }
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
  viewMat  = glm::lookAt(glm::vec3(0,15,15),glm::vec3(0,0,0),glm::vec3(0,1,0));
  modelMat = glm::mat4(1.0f);
  tri vertBuffData[WIDTH*LENGTH*2];
  tri colorBuffData[WIDTH*LENGTH*2];
  genBumpyPlane(WIDTH,LENGTH,vertBuffData,colorBuffData);
  /*
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
  */
  /*
  -0.5,-0.5,-0.5
  -0.5,-0.5,-1.5
  0.5,-0.5,-1.5
  0.5,-0.5,-0.5
  */

  //gen IDs
  gl_programID = loadShader(V_SHADER_FILE, F_SHADER_FILE);
  glGenVertexArrays(1, &gl_vertArrayID);
  glGenBuffers(1, &gl_vertBufferID);
  glGenBuffers(1, &gl_colorBufferID);
  gl_projMatrixID = glGetUniformLocation(gl_programID, "projMat");
  gl_viewMatrixID = glGetUniformLocation(gl_programID, "viewMat");
  gl_modelMatrixID = glGetUniformLocation(gl_programID, "modelMat");

  //populate buffers
  glBindVertexArray(gl_vertArrayID);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, gl_vertBufferID);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertBuffData), (GLfloat *)vertBuffData, GL_STATIC_DRAW);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, gl_colorBufferID);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colorBuffData), (GLfloat *)colorBuffData, GL_STATIC_DRAW);

  glUseProgram(gl_programID);
}

void resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void Graphics::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  modelMat = glm::rotate(modelMat, 0.01f, glm::vec3(0, 1, 0));

  glBindVertexArray(gl_vertArrayID);

  glUniformMatrix4fv(gl_projMatrixID, 1, GL_FALSE, &projMat[0][0]);
  glUniformMatrix4fv(gl_viewMatrixID, 1, GL_FALSE, &viewMat[0][0]);
  glUniformMatrix4fv(gl_modelMatrixID, 1, GL_FALSE, &modelMat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, 3*2*(WIDTH*LENGTH));

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
  glDeleteVertexArrays(1, &gl_vertArrayID);
  glDeleteBuffers(1, &gl_vertBufferID);
  glDeleteBuffers(1, &gl_colorBufferID);
  glDeleteProgram(gl_programID);
}

