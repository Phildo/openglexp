#include "hud_renderer.h"

HUDRenderer::HUDRenderer()
{
  viewMat = glm::mat4(1.0);

  gl_program_id = Renderer::loadShader("/Users/pdougherty/Desktop/flat/src/shaders/h_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/h_shader.fs");

  //gen IDs
  glGenVertexArrays(1, &gl_vert_array_id);
  glGenBuffers(1, &gl_pos_buff_id);
  glGenBuffers(1, &gl_color_buff_id);
  gl_view_mat_id  = glGetUniformLocation(gl_program_id, "viewMat");

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

void HUDRenderer::loadVertData(const HUDComponent& rc) const
{
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vert_array_id);

  glBindBuffer(GL_ARRAY_BUFFER, gl_pos_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.posData, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_color_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.colorData, GL_STATIC_DRAW);
}

void HUDRenderer::render(const HUDComponent& rc) const
{
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vert_array_id);
  glUniformMatrix4fv(gl_view_mat_id,  1, GL_FALSE, &viewMat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, rc.numVerts);
}

HUDRenderer::~HUDRenderer()
{
  glDeleteVertexArrays(1, &gl_vert_array_id);
  glDeleteBuffers(1, &gl_pos_buff_id);
  glDeleteBuffers(1, &gl_color_buff_id);
  glDeleteProgram(gl_program_id);
}

