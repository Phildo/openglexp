#include "world_renderer.h"
#include "Camera.h"

WorldRenderer::WorldRenderer(Graphics* g) : Renderer(g)
{
  //Just 'constants' to better illustrate what the inputs that take ints are actually doing
  GLuint attrib_0 = 0;
  GLuint attrib_1 = 1;

  //Draw
  gl_draw_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/w_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/w_shader.fs");
    //gen IDs
  glGenVertexArrays(1, &gl_draw_vert_array_id);
  glGenBuffers(1, &gl_draw_pos_buff_id);
  glGenBuffers(1, &gl_draw_color_buff_id);
  gl_draw_proj_mat_id  = glGetUniformLocation(gl_draw_program_id, "projMat");
  gl_draw_view_mat_id  = glGetUniformLocation(gl_draw_program_id, "viewMat");
  gl_draw_model_mat_id = glGetUniformLocation(gl_draw_program_id, "modelMat");
  gl_draw_t_id         = glGetUniformLocation(gl_draw_program_id, "t");
  t = 0;
    //set up VAO
  glUseProgram(gl_draw_program_id);
  glBindVertexArray(gl_draw_vert_array_id);
    //pos
  glEnableVertexAttribArray(attrib_0);
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_pos_buff_id);
  glVertexAttribPointer(attrib_0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    //color
  glEnableVertexAttribArray(attrib_1);
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_color_buff_id);
  glVertexAttribPointer(attrib_1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  //Blit
  gl_blit_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/blit_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/blit_shader.fs");
    //gen IDs
  glGenVertexArrays(1, &gl_blit_vert_array_id);
  glGenBuffers(1, &gl_blit_pos_buff_id);
  gl_blit_tex_id = glGetUniformLocation(gl_blit_program_id, "tex");
    //set up VAO
  glUseProgram(gl_blit_program_id);
  glBindVertexArray(gl_blit_vert_array_id);
    //pos
  glEnableVertexAttribArray(attrib_0);
  glBindBuffer(GL_ARRAY_BUFFER, gl_blit_pos_buff_id);
  glVertexAttribPointer(attrib_0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    //just upload the data now- won't change
  screen_quad.posData[0] = glm::vec3(-1.0,-1.0,0.0);
  screen_quad.posData[1] = glm::vec3( 1.0,-1.0,0.0);
  screen_quad.posData[2] = glm::vec3( 1.0, 1.0,0.0);
  screen_quad.posData[3] = glm::vec3(-1.0,-1.0,0.0);
  screen_quad.posData[4] = glm::vec3( 1.0, 1.0,0.0);
  screen_quad.posData[5] = glm::vec3(-1.0, 1.0,0.0);
  screen_quad.numVerts = 6;
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*screen_quad.numVerts, (GLfloat *)screen_quad.posData, GL_STATIC_DRAW);

  //set up FB
  glGenFramebuffers(1, &gl_fb_id);
  glGenTextures(1, &gl_fb_tex_buff_id);
  glGenRenderbuffers(1, &gl_fb_depth_buff_id);
  glBindFramebuffer(GL_FRAMEBUFFER, gl_fb_id);

  glBindTexture(GL_TEXTURE_2D, gl_fb_tex_buff_id);
  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, graphics->sWidth, graphics->sHeight, 0,GL_RGB, GL_UNSIGNED_BYTE, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, gl_fb_tex_buff_id, 0);

  glBindRenderbuffer(GL_RENDERBUFFER, gl_fb_depth_buff_id);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, graphics->sWidth, graphics->sHeight);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, gl_fb_depth_buff_id);

  GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
  glDrawBuffers(1, DrawBuffers);
}

void WorldRenderer::loadVertData(const WorldComponent& rc) const
{
  glUseProgram(gl_draw_program_id);
  glBindVertexArray(gl_draw_vert_array_id);

  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_pos_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.posData, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_color_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.colorData, GL_STATIC_DRAW);
}

void WorldRenderer::render(const Camera* cam, const WorldComponent& rc) const
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_fb_id);
  glUseProgram(gl_draw_program_id);
  glBindVertexArray(gl_draw_vert_array_id);
  glUniformMatrix4fv(gl_draw_proj_mat_id,  1, GL_FALSE, &cam->projMat[0][0]);
  glUniformMatrix4fv(gl_draw_view_mat_id,  1, GL_FALSE, &cam->viewMat[0][0]);
  glUniformMatrix4fv(gl_draw_model_mat_id, 1, GL_FALSE, &rc.modelMat[0][0]);
  glUniform1f(gl_draw_t_id, t);
  glDrawArrays(GL_TRIANGLES, 0, rc.numVerts);
}

void WorldRenderer::blit() const
{
  glBindFramebuffer(GL_FRAMEBUFFER,0);
  glUseProgram(gl_blit_program_id);
  glBindVertexArray(gl_blit_vert_array_id);
  glDrawArrays(GL_TRIANGLES, 0, screen_quad.numVerts);
}

void WorldRenderer::update()
{
  t+=0.01f;
}

WorldRenderer::~WorldRenderer()
{
  glDeleteVertexArrays(1, &gl_blit_vert_array_id);
  glDeleteBuffers(1, &gl_blit_pos_buff_id);
  glDeleteProgram(gl_blit_program_id);

  glDeleteVertexArrays(1, &gl_draw_vert_array_id);
  glDeleteBuffers(1, &gl_draw_pos_buff_id);
  glDeleteBuffers(1, &gl_draw_color_buff_id);
  glDeleteProgram(gl_draw_program_id);
}

