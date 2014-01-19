#include "gl_include.h"
#include "FLAT_include.h"

class ShaderProgram
{
  private:
    GLuint loadShader(const char *vs_filename, const char *fs_filename);
  public:
    GLuint gl_program_id;
    GLuint gl_vertArray_id;

    virtual ShaderProgram(const char* vs_filename, const char* fs_filename);
    virtual ~ShaderProgram();

    void useProgram();
};

