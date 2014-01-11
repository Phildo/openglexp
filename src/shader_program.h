#include "gl_include.h"
#include "FLAT_include.h"

class ShaderProgram
{
  private:
  public:
    GLuint gl_program_id;

    ShaderProgram(const char* vs_filename, const char* fs_filename);
    ~ShaderProgram();

    void useProgram();
};

