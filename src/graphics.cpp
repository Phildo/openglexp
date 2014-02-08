#include "graphics.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stdlib.h>

#define WIDTH 64
#define LENGTH 64

struct pt
{
  GLfloat x,y,z;
};

struct tri
{
  pt p0,p1,p2;
};

/*
void genBumpyPlane(int widthx, int lengthz, tri* verts, tri* colors)
{
  pt p0,p1,p2,p3;
  pt c0,c1,c2,c3;
  tri t;

  for(int x = 0; x < widthx; x++)
  {
    for(int z = 0; z < lengthz; z++)
    {
      p0.x = ((x+0)* 1.0f)+(FLAT_Utils::randf()-0.5f)-(widthx/2.0f);
      p0.y =               (FLAT_Utils::randf()-0.5f);
      p0.z = ((z+0)*-1.0f)+(FLAT_Utils::randf()-0.5f)+(lengthz/2.0f);
      c0.x = (FLAT_Utils::randf()/2.0f+0.5f);
      c0.y = (FLAT_Utils::randf()/2.0f+0.5f);
      c0.z = (FLAT_Utils::randf()/2.0f+0.5f);

      p1.x = ((x+0)* 1.0f)+(FLAT_Utils::randf()-0.5f)-(widthx/2.0f);
      p1.y =               (FLAT_Utils::randf()-0.5f);
      p1.z = ((z+1)*-1.0f)+(FLAT_Utils::randf()-0.5f)+(lengthz/2.0f);
      c1.x = (FLAT_Utils::randf()/2.0f+0.5f);
      c1.y = (FLAT_Utils::randf()/2.0f+0.5f);
      c1.z = (FLAT_Utils::randf()/2.0f+0.5f);

      p2.x = ((x+1)* 1.0f)+(FLAT_Utils::randf()-0.5f)-(widthx/2.0f);
      p2.y =               (FLAT_Utils::randf()-0.5f);
      p2.z = ((z+1)*-1.0f)+(FLAT_Utils::randf()-0.5f)+(lengthz/2.0f);
      c2.x = (FLAT_Utils::randf()/2.0f+0.5f);
      c2.y = (FLAT_Utils::randf()/2.0f+0.5f);
      c2.z = (FLAT_Utils::randf()/2.0f+0.5f);

      p3.x = ((x+1)* 1.0f)+(FLAT_Utils::randf()-0.5f)-(widthx/2.0f);
      p3.y =               (FLAT_Utils::randf()-0.5f);
      p3.z = ((z+0)*-1.0f)+(FLAT_Utils::randf()-0.5f)+(lengthz/2.0f);
      c3.x = (FLAT_Utils::randf()/2.0f+0.5f);
      c3.y = (FLAT_Utils::randf()/2.0f+0.5f);
      c3.z = (FLAT_Utils::randf()/2.0f+0.5f);

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
*/

Graphics::Graphics(const MyGL& mygl)
{
  window = mygl.window;

  glfwSwapInterval(0);
  glfwSetFramebufferSizeCallback(window, resize);

/*
  glClearColor(255,255,255,0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  */
}

void Graphics::resize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void Graphics::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/*
  */

  glfwSwapBuffers(window);
}

Graphics::~Graphics()
{
}

