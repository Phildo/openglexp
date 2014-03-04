#include "world_renderer.h"
#include "Camera.h"

WorldRenderer::WorldRenderer(Graphics* g) : Renderer(g)
{
  //Draw
  gl_draw_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/w_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/w_shader.fs"); //generate
  glUseProgram(gl_draw_program_id); //bind
    //gen VAO
  glGenVertexArrays(1, &gl_draw_vert_array_id); //generate
  glBindVertexArray(gl_draw_vert_array_id); //bind
    //pos buff
  gl_draw_pos_attrib_id = glGetAttribLocation(gl_draw_program_id, "vpos");
  glGenBuffers(1, &gl_draw_pos_buff_id); //generate
  glEnableVertexAttribArray(gl_draw_pos_attrib_id); //enable
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_pos_buff_id); //bind
  glVertexAttribPointer(gl_draw_pos_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); //define
    //color buff
  gl_draw_col_attrib_id = glGetAttribLocation(gl_draw_program_id, "vcol");
  glGenBuffers(1, &gl_draw_color_buff_id); //generate
  glEnableVertexAttribArray(gl_draw_col_attrib_id); //enable
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_color_buff_id); //bind
  glVertexAttribPointer(gl_draw_col_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); //define
    //uniforms
  gl_draw_proj_mat_id  = glGetUniformLocation(gl_draw_program_id, "projMat");
  gl_draw_view_mat_id  = glGetUniformLocation(gl_draw_program_id, "viewMat");
  gl_draw_model_mat_id = glGetUniformLocation(gl_draw_program_id, "modelMat");
  gl_draw_t_id         = glGetUniformLocation(gl_draw_program_id, "t");
  t = 0;

  //Blit
  gl_blit_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/blit_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/blit_shader.fs"); //generate
  glUseProgram(gl_blit_program_id); //bind
    //gen VAO
  glGenVertexArrays(1, &gl_blit_vert_array_id); //generate
  glBindVertexArray(gl_blit_vert_array_id); //bind
    //pos buff
  gl_blit_pos_attrib_id = glGetAttribLocation(gl_blit_program_id, "vpos");
  glGenBuffers(1, &gl_blit_pos_buff_id); //generate
  glEnableVertexAttribArray(gl_blit_pos_attrib_id); //enable
  glBindBuffer(GL_ARRAY_BUFFER, gl_blit_pos_buff_id); //bind
  glVertexAttribPointer(gl_blit_pos_attrib_id,3,GL_FLOAT,GL_FALSE,0,(void*)0); //define
    //uniforms
  gl_blit_col_tex_id = glGetUniformLocation(gl_blit_program_id, "col_tex");
    //just upload the data now- won't change
  screen_quad.posData[0] = glm::vec3(-1.0,-1.0,0.0);
  screen_quad.posData[1] = glm::vec3( 1.0,-1.0,0.0);
  screen_quad.posData[2] = glm::vec3( 1.0, 1.0,0.0);
  screen_quad.posData[3] = glm::vec3(-1.0,-1.0,0.0);
  screen_quad.posData[4] = glm::vec3( 1.0, 1.0,0.0);
  screen_quad.posData[5] = glm::vec3(-1.0, 1.0,0.0);
  screen_quad.numVerts = 6;
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*screen_quad.numVerts, (GLfloat *)screen_quad.posData, GL_STATIC_DRAW); //define

  //set up FB
  glGenFramebuffers(1, &gl_fb_id); //generate
  glBindFramebuffer(GL_FRAMEBUFFER, gl_fb_id); // bind

    //Depth
  glGenTextures(1, &gl_fb_depth_tex_id); //generate
  glBindTexture(GL_TEXTURE_2D, gl_fb_depth_tex_id); //bind
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, graphics->sWidth/4, graphics->sHeight/4, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0); //define
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //attrib
  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, gl_fb_depth_tex_id, 0); //attach

    //Color
  glGenTextures(1, &gl_fb_col_tex_id); //generate
  glBindTexture(GL_TEXTURE_2D, gl_fb_col_tex_id); //bind
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/4, graphics->sHeight/4, 0, GL_RGB, GL_UNSIGNED_BYTE, 0); //define
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //attrib
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, gl_fb_col_tex_id, 0); //attach

  // Alternative to render depth to renderbuffer rather than texture
  //glGenRenderbuffers(1, &gl_fb_depth_buff_id); //generate
  //glBindRenderbuffer(GL_RENDERBUFFER, gl_fb_depth_buff_id); //bind
  //glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, graphics->sWidth/4, graphics->sHeight/4); //define
  //glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, gl_fb_depth_buff_id); //attach

  //GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
  //glDrawBuffers(1, DrawBuffers);
}

void WorldRenderer::loadVertData(const WorldComponent& rc) const
{
  glBindVertexArray(gl_draw_vert_array_id); //bind
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_pos_buff_id); //bind
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.posData, GL_STATIC_DRAW); //define
  glBindBuffer(GL_ARRAY_BUFFER, gl_draw_color_buff_id); //bind
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.colorData, GL_STATIC_DRAW); //define
}

void WorldRenderer::prepareForDraw()
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_fb_id);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth/4,graphics->sHeight/4);
}

void WorldRenderer::render(const Camera* cam, const WorldComponent& rc) const
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_fb_id); //bind
  glUseProgram(gl_draw_program_id); //bind
  glBindVertexArray(gl_draw_vert_array_id); //bind
  glUniformMatrix4fv(gl_draw_proj_mat_id,  1, GL_FALSE, &cam->projMat[0][0]); //define
  glUniformMatrix4fv(gl_draw_view_mat_id,  1, GL_FALSE, &cam->viewMat[0][0]); //define
  glUniformMatrix4fv(gl_draw_model_mat_id, 1, GL_FALSE, &rc.modelMat[0][0]); //define
  glUniform1f(gl_draw_t_id, t); //define
  glDrawArrays(GL_TRIANGLES, 0, rc.numVerts); //draw
}

void WorldRenderer::blit() const
{
  glBindFramebuffer(GL_FRAMEBUFFER,0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth,graphics->sHeight);

  glBindFramebuffer(GL_FRAMEBUFFER,0); //bind
  glUseProgram(gl_blit_program_id); //bind
  glBindVertexArray(gl_blit_vert_array_id); //bind
  glDrawArrays(GL_TRIANGLES, 0, screen_quad.numVerts); //draw
}

void WorldRenderer::update()
{
  t+=0.01f;
}

WorldRenderer::~WorldRenderer()
{
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glDeleteTextures(1, &gl_fb_col_tex_id);
  glDeleteTextures(1, &gl_fb_depth_tex_id);
  //glDeleteRenderbuffers(1, &gl_fb_depth_buff_id); //alternative to depth2tex
  glDeleteFramebuffers(1, &gl_fb_id);

  glDeleteVertexArrays(1, &gl_blit_vert_array_id);
  glDeleteBuffers(1, &gl_blit_pos_buff_id);
  glDeleteProgram(gl_blit_program_id);

  glDeleteVertexArrays(1, &gl_draw_vert_array_id);
  glDeleteBuffers(1, &gl_draw_pos_buff_id);
  glDeleteBuffers(1, &gl_draw_color_buff_id);
  glDeleteProgram(gl_draw_program_id);
}

