#include "basic_renderer.h"
#include "FLAT_utils.h"
#include <string>

GLuint loadShader(const char *vs_filename, const char *fs_filename)
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

BasicRenderer::BasicRenderer()
{
  gl_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/shader.fs");//vs_filename, fs_filename);

  //gen IDs
  glGenVertexArrays(1, &gl_vert_array_id);
  glGenBuffers(1, &gl_pos_buff_id);
  glGenBuffers(1, &gl_color_buff_id);
  gl_proj_mat_id  = glGetUniformLocation(gl_program_id, "projMat");
  gl_view_mat_id  = glGetUniformLocation(gl_program_id, "viewMat");
  gl_model_mat_id = glGetUniformLocation(gl_program_id, "modelMat");

  //set up VAO
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vert_array_id);

  GLuint attrib_0 = 0;
  glEnableVertexAttribArray(attrib_0);
  glBindBuffer(GL_ARRAY_BUFFER, gl_pos_buff_id);
  glVertexAttribPointer(attrib_0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  GLuint attrib_1 = 1;
  glEnableVertexAttribArray(attrib_1);
  glBindBuffer(GL_ARRAY_BUFFER, gl_color_buff_id);
  glVertexAttribPointer(attrib_1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
}

BasicRenderer::~BasicRenderer()
{
  glDeleteVertexArrays(1, &gl_vert_array_id);
  glDeleteBuffers(1, &gl_pos_buff_id);
  glDeleteBuffers(1, &gl_color_buff_id);
  glDeleteProgram(gl_program_id);
}

void BasicRenderer::loadVertData(const RenderComponent& rc) const
{
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vert_array_id);

  glBindBuffer(GL_ARRAY_BUFFER, gl_pos_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.posData, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_color_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.colorData, GL_STATIC_DRAW);
}

void BasicRenderer::render(const Camera& cam, const RenderComponent& rc) const
{
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vert_array_id);
  glUniformMatrix4fv(gl_proj_mat_id,  1, GL_FALSE, &cam.projMat[0][0]);
  glUniformMatrix4fv(gl_view_mat_id,  1, GL_FALSE, &cam.viewMat[0][0]);
  glUniformMatrix4fv(gl_model_mat_id, 1, GL_FALSE, &rc.modelMat[0][0]);
  glDrawArrays(GL_TRIANGLES, 0, rc.numVerts);
}

