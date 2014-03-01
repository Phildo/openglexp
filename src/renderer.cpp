#include "renderer.h"
#include "FLAT_utils.h"
#include <string>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

GLuint Renderer::loadShader(const char *vs_filename, const char *fs_filename)
{
  GLuint gl_program_id;
  GLuint gl_vs_id = glCreateShader(GL_VERTEX_SHADER);
  GLuint gl_fs_id = glCreateShader(GL_FRAGMENT_SHADER);

  std::string fileContents;
  FLAT_Utils::stringFromFile(vs_filename, fileContents);
  const char *vscp = fileContents.c_str();
  glShaderSource(gl_vs_id, 1, &vscp, NULL);
  glCompileShader(gl_vs_id);

  FLAT_Utils::stringFromFile(fs_filename, fileContents);
  const char *fscp = fileContents.c_str();
  glShaderSource(gl_fs_id, 1, &fscp, NULL);
  glCompileShader(gl_fs_id);

  gl_program_id = glCreateProgram();
  glAttachShader(gl_program_id, gl_vs_id);
  glAttachShader(gl_program_id, gl_fs_id);
  glLinkProgram(gl_program_id);

  glDeleteShader(gl_vs_id);
  glDeleteShader(gl_fs_id);

  return gl_program_id;
}

