#include "world_renderer.h"
#include "Camera.h"

#define POT 8

WorldRenderer::WorldRenderer(Graphics* g) : Renderer(g)
{
  //Geometry Pass
  gl_g_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/g_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/g_shader.fs"); //generate
  glUseProgram(gl_g_program_id); //bind
    //gen VAO
  glGenVertexArrays(1, &gl_g_vert_array_id); //generate
  glBindVertexArray(gl_g_vert_array_id); //bind
    //pos buff
  gl_g_pos_attrib_id = glGetAttribLocation(gl_g_program_id, "vpos");
  glGenBuffers(1, &gl_g_pos_buff_id); //generate
  glEnableVertexAttribArray(gl_g_pos_attrib_id); //enable
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_pos_buff_id); //bind
  glVertexAttribPointer(gl_g_pos_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); //define
    //color buff
  gl_g_col_attrib_id = glGetAttribLocation(gl_g_program_id, "vcol");
  glGenBuffers(1, &gl_g_color_buff_id); //generate
  glEnableVertexAttribArray(gl_g_col_attrib_id); //enable
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_color_buff_id); //bind
  glVertexAttribPointer(gl_g_col_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); //define
    //uniforms
  gl_g_proj_mat_id  = glGetUniformLocation(gl_g_program_id, "projMat");
  gl_g_view_mat_id  = glGetUniformLocation(gl_g_program_id, "viewMat");
  gl_g_model_mat_id = glGetUniformLocation(gl_g_program_id, "modelMat");

  //Light Pass
  gl_l_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/l_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/l_shader.fs"); //generate
  glUseProgram(gl_l_program_id); //bind
    //gen VAO
  glGenVertexArrays(1, &gl_l_vert_array_id); //generate
  glBindVertexArray(gl_l_vert_array_id); //bind
    //pos buff
  gl_l_pos_attrib_id = glGetAttribLocation(gl_l_program_id, "vpos");
  glGenBuffers(1, &gl_l_pos_buff_id); //generate
  glEnableVertexAttribArray(gl_l_pos_attrib_id); //enable
  glBindBuffer(GL_ARRAY_BUFFER, gl_l_pos_buff_id); //bind
  glVertexAttribPointer(gl_l_pos_attrib_id,3,GL_FLOAT,GL_FALSE,0,(void*)0); //define
    //uniforms
  gl_l_col_tex_id = glGetUniformLocation(gl_l_program_id, "col_tex");
  gl_l_pos_tex_id = glGetUniformLocation(gl_l_program_id, "pos_tex");
  gl_l_dep_tex_id = glGetUniformLocation(gl_l_program_id, "dep_tex");
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

    //Color
  glActiveTexture(GL_TEXTURE0 + 0);
  glGenTextures(1, &gl_fb_col_tex_id); //generate
  glBindTexture(GL_TEXTURE_2D, gl_fb_col_tex_id); //bind
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_RGB, GL_UNSIGNED_BYTE, 0); //define
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //attrib
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, gl_fb_col_tex_id, 0); //attach
  glUniform1i(gl_l_col_tex_id, 0);

    //Position
  glActiveTexture(GL_TEXTURE0 + 1);
  glGenTextures(1, &gl_fb_pos_tex_id); //generate
  glBindTexture(GL_TEXTURE_2D, gl_fb_pos_tex_id); //bind
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_RGB, GL_UNSIGNED_BYTE, 0); //define
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //attrib
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, gl_fb_pos_tex_id, 0); //attach
  glUniform1i(gl_l_pos_tex_id, 1);

    //Depth
  glActiveTexture(GL_TEXTURE0 + 2);
  glGenTextures(1, &gl_fb_dep_tex_id); //generate
  glBindTexture(GL_TEXTURE_2D, gl_fb_dep_tex_id); //bind
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0); //define
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //attrib
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //attrib
  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, gl_fb_dep_tex_id, 0); //attach
  glUniform1i(gl_l_dep_tex_id, 2);

  // Alternative to render depth to renderbuffer rather than texture
  //glGenRenderbuffers(1, &gl_fb_dep_buff_id); //generate
  //glBindRenderbuffer(GL_RENDERBUFFER, gl_fb_dep_buff_id); //bind
  //glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, graphics->sWidth/POT, graphics->sHeight/POT); //define
  //glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, gl_fb_depth_buff_id); //attach

  GLenum drawBuffers[2] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1};
  glDrawBuffers(2, drawBuffers);
}

void WorldRenderer::loadVertData(const WorldComponent& rc) const
{
  glBindVertexArray(gl_g_vert_array_id); //bind
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_pos_buff_id); //bind
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.posData, GL_STATIC_DRAW); //define
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_color_buff_id); //bind
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*rc.numVerts, (GLfloat *)rc.colorData, GL_STATIC_DRAW); //define
}

void WorldRenderer::prepareForDraw()
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_fb_id);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth/POT,graphics->sHeight/POT);
}

void WorldRenderer::render(const Camera* cam, const WorldComponent& rc) const
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_fb_id); //bind
  glUseProgram(gl_g_program_id); //bind
  glBindVertexArray(gl_g_vert_array_id); //bind
  glUniformMatrix4fv(gl_g_proj_mat_id,  1, GL_FALSE, &cam->projMat[0][0]); //define
  glUniformMatrix4fv(gl_g_view_mat_id,  1, GL_FALSE, &cam->viewMat[0][0]); //define
  glUniformMatrix4fv(gl_g_model_mat_id, 1, GL_FALSE, &rc.modelMat[0][0]); //define
  glDrawArrays(GL_TRIANGLES, 0, rc.numVerts); //draw
}

void WorldRenderer::light() const
{
  glBindFramebuffer(GL_FRAMEBUFFER,0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth,graphics->sHeight);

  glBindFramebuffer(GL_FRAMEBUFFER,0); //bind
  glUseProgram(gl_l_program_id); //bind
  glBindVertexArray(gl_l_vert_array_id); //bind
  glDrawArrays(GL_TRIANGLES, 0, screen_quad.numVerts); //draw
}

WorldRenderer::~WorldRenderer()
{
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glDeleteTextures(1, &gl_fb_col_tex_id);
  glDeleteTextures(1, &gl_fb_pos_tex_id);
  glDeleteTextures(1, &gl_fb_dep_tex_id);
  //glDeleteRenderbuffers(1, &gl_fb_dep_buff_id); //alternative to depth2tex
  glDeleteFramebuffers(1, &gl_fb_id);

  glDeleteVertexArrays(1, &gl_l_vert_array_id);
  glDeleteBuffers(1, &gl_l_pos_buff_id);
  glDeleteProgram(gl_l_program_id);

  glDeleteVertexArrays(1, &gl_g_vert_array_id);
  glDeleteBuffers(1, &gl_g_pos_buff_id);
  glDeleteBuffers(1, &gl_g_color_buff_id);
  glDeleteProgram(gl_g_program_id);
}

