#include "my_shader_program.h"

MyShaderProgram::MyShaderProgram(const char* vs_filename, const char* fs_filename)
{
  ShaderProgram(vs_filename, fs_filename);
}

MyShaderProgram::~MyShaderProgram()
{
}

