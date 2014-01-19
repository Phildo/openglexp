#include "shader_program.h"

GLuint ShaderProgram::loadShader(const char *vs_filename, const char *fs_filename)
{
  GLuint gl_program_id;
  GLuint gl_vs_id = glCreateShader(GL_VERTEX_SHADER);
  GLuint gl_fs_id = glCreateShader(GL_FRAGMENT_SHADER);

  std::string fileContents;
  FLATUtils::stringFromFile(vs_filename, fileContents);
  const char *vscp = fileContents.c_str();
  glShaderSource(gl_vs_id, 1, &vscp, NULL);
  glCompileShader(gl_vs_id);

  FLATUtils::stringFromFile(fs_filename, fileContents);
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

ShaderProgram::ShaderProgram(const char* vs_filename, const char* fs_filename)
{
  gl_program_id = loadShader(vs_filename, fs_filename);
  glGenVertexArrays(1, &gl_vertArray_id);
}

ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(gl_program_id);
}

void ShaderProgram::useProgram()
{
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vertArray_id);
}

