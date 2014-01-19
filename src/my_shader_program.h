#include "shader_program.h"

class MyShaderProgram : public ShaderProgram
{
  private:
  public:
    MyShaderProgram(const char* vs_filename, const char* fs_filename);
    ~MyShaderProgram();
};

