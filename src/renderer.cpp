#include "renderer.h"
#include "FLAT_utils.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define VERBOSE

Renderer::Renderer() { }

Renderer::~Renderer() { }

GLuint Renderer::loadShader(const char *vs_filename, const char *fs_filename)
{
  GLuint gl_program_id;
  GLuint gl_vs_id = glCreateShader(GL_VERTEX_SHADER);
  GLuint gl_fs_id = glCreateShader(GL_FRAGMENT_SHADER);

  GLint err;

  std::string fileContents;
  FLAT_Utils::stringFromFile(vs_filename, fileContents);
  const char *vscp = fileContents.c_str();
  glShaderSource(gl_vs_id, 1, &vscp, NULL);
  glCompileShader(gl_vs_id);

  FLAT_Utils::stringFromFile(fs_filename, fileContents);
  const char *fscp = fileContents.c_str();
  glShaderSource(gl_fs_id, 1, &fscp, NULL);
  glCompileShader(gl_fs_id);

  #ifdef VERBOSE
    glGetShaderiv(gl_vs_id, GL_COMPILE_STATUS, &err);
    if(err == GL_FALSE) std::cout << "Error compiling " << vs_filename << std::endl;
    glGetShaderiv(gl_fs_id, GL_COMPILE_STATUS, &err);
    if(err == GL_FALSE) std::cout << "Error compiling " << fs_filename << std::endl;
  #endif

  gl_program_id = glCreateProgram();
  glAttachShader(gl_program_id, gl_vs_id);
  glAttachShader(gl_program_id, gl_fs_id);
  glLinkProgram(gl_program_id);

  #ifdef VERBOSE
    glGetProgramiv(gl_fs_id, GL_LINK_STATUS, &err);
    if(err == GL_FALSE) std::cout << "Error linking " << fs_filename << " & " << vs_filename << std::endl;
  #endif

  glDeleteShader(gl_vs_id);
  glDeleteShader(gl_fs_id);

  return gl_program_id;
}

