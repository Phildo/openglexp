#include "world_renderer.h"
#include "Camera.h"

#define POT 4

WorldRenderer::WorldRenderer(Graphics* g) : Renderer(g)
{
  //init the quad
  screen_quad.pos[0] = glm::vec3(-1.0,-1.0,0.0);
  screen_quad.pos[1] = glm::vec3( 1.0,-1.0,0.0);
  screen_quad.pos[2] = glm::vec3( 1.0, 1.0,0.0);
  screen_quad.pos[3] = glm::vec3(-1.0,-1.0,0.0);
  screen_quad.pos[4] = glm::vec3( 1.0, 1.0,0.0);
  screen_quad.pos[5] = glm::vec3(-1.0, 1.0,0.0);
  screen_quad.numVerts = 6;


  //Geometry Pass
  gl_g_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/g_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/g_shader.fs");
  glUseProgram(gl_g_program_id);

    //uniforms
  gl_g_view_mat_id  = glGetUniformLocation(gl_g_program_id, "viewMat");
  gl_g_proj_mat_id  = glGetUniformLocation(gl_g_program_id, "projMat");
  gl_g_model_mat_a_id = glGetUniformLocation(gl_g_program_id, "modelMatA");
  gl_g_model_mat_r_id = glGetUniformLocation(gl_g_program_id, "modelMatR");
    //attribs
  gl_g_pos_attrib_id  = glGetAttribLocation(gl_g_program_id, "vpos");
  gl_g_col_attrib_id  = glGetAttribLocation(gl_g_program_id, "vcol");
  gl_g_norm_attrib_id = glGetAttribLocation(gl_g_program_id, "vnorm");

    //gen VAO
  glGenVertexArrays(1, &gl_g_vert_array_id);
  glBindVertexArray(gl_g_vert_array_id);
    //pos buff
  glGenBuffers(1, &gl_g_pos_buff_id);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_pos_buff_id);
  glVertexAttribPointer(gl_g_pos_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(gl_g_pos_attrib_id);
    //color buff
  glGenBuffers(1, &gl_g_col_buff_id);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_col_buff_id);
  glVertexAttribPointer(gl_g_col_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(gl_g_col_attrib_id);
    //normal buff
  glGenBuffers(1, &gl_g_norm_buff_id);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_norm_buff_id);
  glVertexAttribPointer(gl_g_norm_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(gl_g_norm_attrib_id);

    //gen FB
  glGenFramebuffers(1, &gl_g_fb_id);
  glBindFramebuffer(GL_FRAMEBUFFER, gl_g_fb_id);

    //Position
  glActiveTexture(GL_TEXTURE0 + 0);
  glGenTextures(1, &gl_g_fb_pos_tex_id);
  glBindTexture(GL_TEXTURE_2D, gl_g_fb_pos_tex_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_RGB, GL_FLOAT, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 0, gl_g_fb_pos_tex_id, 0);

    //Color
  glActiveTexture(GL_TEXTURE0 + 1);
  glGenTextures(1, &gl_g_fb_col_tex_id);
  glBindTexture(GL_TEXTURE_2D, gl_g_fb_col_tex_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_RGB, GL_FLOAT, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 1, gl_g_fb_col_tex_id, 0);

    //Normal
  glActiveTexture(GL_TEXTURE0 + 2);
  glGenTextures(1, &gl_g_fb_norm_tex_id);
  glBindTexture(GL_TEXTURE_2D, gl_g_fb_norm_tex_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_RGB, GL_FLOAT, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 2, gl_g_fb_norm_tex_id, 0);

    //Depth
  glActiveTexture(GL_TEXTURE0 + 3);
  glGenTextures(1, &gl_g_fb_dep_tex_id);
  glBindTexture(GL_TEXTURE_2D, gl_g_fb_dep_tex_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, gl_g_fb_dep_tex_id, 0);

  // Alternative to render depth to renderbuffer rather than texture
  //glGenRenderbuffers(1, &gl_g_fb_dep_buff_id);
  //glBindRenderbuffer(GL_RENDERBUFFER, gl_g_fb_dep_buff_id);
  //glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, graphics->sWidth/POT, graphics->sHeight/POT);
  //glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, gl_g_fb_depth_buff_id);


  //Shadow Pass
  gl_s_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/s_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/s_shader.fs");
  glUseProgram(gl_s_program_id);

    //uniforms
  gl_s_view_mat_id  = glGetUniformLocation(gl_s_program_id, "viewMat");
  gl_s_proj_mat_id  = glGetUniformLocation(gl_s_program_id, "projMat");
  gl_s_model_mat_a_id = glGetUniformLocation(gl_s_program_id, "modelMatA");
  gl_s_model_mat_r_id = glGetUniformLocation(gl_s_program_id, "modelMatR");
    //attribs
  gl_s_pos_attrib_id  = glGetAttribLocation(gl_s_program_id, "vpos");

    //gen VAO
  glGenVertexArrays(1, &gl_s_vert_array_id);
  glBindVertexArray(gl_s_vert_array_id);
    //pos buff
  glGenBuffers(1, &gl_s_pos_buff_id);
  glBindBuffer(GL_ARRAY_BUFFER, gl_s_pos_buff_id);
  glVertexAttribPointer(gl_s_pos_attrib_id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(gl_s_pos_attrib_id);

    //gen FB
  glGenFramebuffers(1, &gl_s_fb_id);
  glBindFramebuffer(GL_FRAMEBUFFER, gl_s_fb_id);

    //Depth
  glActiveTexture(GL_TEXTURE0 + 4);
  glGenTextures(1, &gl_s_fb_dep_tex_id);
  glBindTexture(GL_TEXTURE_2D, gl_s_fb_dep_tex_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, gl_s_fb_dep_tex_id, 0);


  //Light Pass
  gl_a_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/a_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/a_shader.fs");
  glUseProgram(gl_a_program_id);

    //uniforms
  gl_a_pos_tex_id    = glGetUniformLocation(gl_a_program_id, "pos_tex");
  gl_a_col_tex_id    = glGetUniformLocation(gl_a_program_id, "col_tex");
  gl_a_norm_tex_id   = glGetUniformLocation(gl_a_program_id, "norm_tex");
  gl_a_dep_tex_id    = glGetUniformLocation(gl_a_program_id, "dep_tex");
  gl_a_shadow_tex_id = glGetUniformLocation(gl_a_program_id, "shadow_tex");
  gl_a_tex_id        = glGetUniformLocation(gl_a_program_id, "accum_tex"); //same tex being drawn to
  gl_a_pos_vec_id    = glGetUniformLocation(gl_a_program_id, "posVec");
  gl_a_view_mat_id   = glGetUniformLocation(gl_a_program_id, "viewMat");
  gl_a_proj_mat_id   = glGetUniformLocation(gl_a_program_id, "projMat");
    //attribs
  gl_a_pos_attrib_id = glGetAttribLocation(gl_a_program_id, "vpos");

    //gen VAO
  glGenVertexArrays(1, &gl_a_vert_array_id);
  glBindVertexArray(gl_a_vert_array_id);
    //pos buff
  glGenBuffers(1, &gl_a_pos_buff_id);
  glBindBuffer(GL_ARRAY_BUFFER, gl_a_pos_buff_id);
  glVertexAttribPointer(gl_a_pos_attrib_id,3,GL_FLOAT,GL_FALSE,0,(void*)0);
  glEnableVertexAttribArray(gl_a_pos_attrib_id);
    //just upload the data now- won't change
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*screen_quad.numVerts, (GLfloat *)screen_quad.pos, GL_STATIC_DRAW);

  //Accumulation(light) FB
  glGenFramebuffers(1, &gl_a_fb_id);
  glBindFramebuffer(GL_FRAMEBUFFER, gl_a_fb_id);

    //Color
  glActiveTexture(GL_TEXTURE0 + 4);
  glGenTextures(1, &gl_a_fb_tex_id);
  glBindTexture(GL_TEXTURE_2D, gl_a_fb_tex_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, graphics->sWidth/POT, graphics->sHeight/POT, 0, GL_RGB, GL_FLOAT, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 0, gl_a_fb_tex_id, 0);


  //Blit Pass
  gl_b_program_id = loadShader("/Users/pdougherty/Desktop/flat/src/shaders/blit_shader.vs","/Users/pdougherty/Desktop/flat/src/shaders/blit_shader.fs");
  glUseProgram(gl_b_program_id);

    //uniforms
  gl_b_tex_id = glGetUniformLocation(gl_b_program_id, "tex");
    //attribs
  gl_b_pos_attrib_id = glGetAttribLocation(gl_b_program_id, "vpos");

    //gen VAO
  glGenVertexArrays(1, &gl_b_vert_array_id);
  glBindVertexArray(gl_b_vert_array_id);
    //pos buff
  glGenBuffers(1, &gl_b_pos_buff_id);
  glBindBuffer(GL_ARRAY_BUFFER, gl_b_pos_buff_id);
  glVertexAttribPointer(gl_b_pos_attrib_id,3,GL_FLOAT,GL_FALSE,0,(void*)0);
  glEnableVertexAttribArray(gl_b_pos_attrib_id);
    //just upload the data now- won't change
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*screen_quad.numVerts, (GLfloat *)screen_quad.pos, GL_STATIC_DRAW);
}

void WorldRenderer::loadGeoVertData(const GeoComponent& gc) const
{
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_pos_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*gc.numVerts, (GLfloat *)gc.pos, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_col_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*gc.numVerts, (GLfloat *)gc.color, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_norm_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*gc.numVerts, (GLfloat *)gc.norm, GL_STATIC_DRAW);
}

void WorldRenderer::prepareForGeo(const Camera* cam) const
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_g_fb_id);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth/POT,graphics->sHeight/POT);
  glUseProgram(gl_g_program_id);
  GLenum drawBuffers[3] = {GL_COLOR_ATTACHMENT0 + 0, GL_COLOR_ATTACHMENT0 + 1, GL_COLOR_ATTACHMENT0 + 2};
  glDrawBuffers(3, drawBuffers);

  glBindVertexArray(gl_g_vert_array_id);
  glUniformMatrix4fv(gl_g_proj_mat_id, 1, GL_FALSE, &cam->projMat[0][0]);
  glUniformMatrix4fv(gl_g_view_mat_id, 1, GL_FALSE, &cam->viewMat[0][0]);
}

void WorldRenderer::renderGeo(const GeoComponent& gc) const
{
  glUniformMatrix4fv(gl_g_model_mat_a_id, 1, GL_FALSE, &gc.modelMatA[0][0]);
  glUniformMatrix4fv(gl_g_model_mat_r_id, 1, GL_FALSE, &gc.modelMatR[0][0]);
  glDrawArrays(GL_TRIANGLES, 0, gc.numVerts);
}

void WorldRenderer::loadShadowVertData(const GeoComponent& gc) const
{
/*
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_pos_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*gc.numVerts, (GLfloat *)gc.pos, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_col_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*gc.numVerts, (GLfloat *)gc.color, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, gl_g_norm_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*gc.numVerts, (GLfloat *)gc.norm, GL_STATIC_DRAW);
*/
}

void WorldRenderer::prepareForShadow(const Camera* cam) const
{
/*
  glBindFramebuffer(GL_FRAMEBUFFER,gl_g_fb_id);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth/POT,graphics->sHeight/POT);
  glUseProgram(gl_g_program_id);
  GLenum drawBuffers[3] = {GL_COLOR_ATTACHMENT0 + 0, GL_COLOR_ATTACHMENT0 + 1, GL_COLOR_ATTACHMENT0 + 2};
  glDrawBuffers(3, drawBuffers);

  glBindVertexArray(gl_g_vert_array_id);
  glUniformMatrix4fv(gl_g_proj_mat_id, 1, GL_FALSE, &cam->projMat[0][0]);
  glUniformMatrix4fv(gl_g_view_mat_id, 1, GL_FALSE, &cam->viewMat[0][0]);
*/
}

void WorldRenderer::genShadowMap(const LightComponent& lc) const
{
/*
  glUniformMatrix4fv(gl_g_model_mat_a_id, 1, GL_FALSE, &gc.modelMatA[0][0]);
  glUniformMatrix4fv(gl_g_model_mat_r_id, 1, GL_FALSE, &gc.modelMatR[0][0]);
  glDrawArrays(GL_TRIANGLES, 0, gc.numVerts);
*/
}

void WorldRenderer::prepareForLight(const Camera* cam) const
{
  glBindFramebuffer(GL_FRAMEBUFFER,gl_a_fb_id);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth/POT,graphics->sHeight/POT);
  glUseProgram(gl_a_program_id);
  GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0 + 0};
  glDrawBuffers(1, drawBuffers);

  glBindVertexArray(gl_a_vert_array_id);
  glUniform1i(gl_a_pos_tex_id, 0);
  glUniform1i(gl_a_col_tex_id, 1);
  glUniform1i(gl_a_norm_tex_id, 2);
  glUniform1i(gl_a_dep_tex_id, 3);
  glUniform1i(gl_a_shadow_tex_id, 4);
  glUniform1i(gl_a_tex_id, 5); //the same tex being drawn to

  glUniformMatrix4fv(gl_a_proj_mat_id, 1, GL_FALSE, &cam->projMat[0][0]);
  glUniformMatrix4fv(gl_a_view_mat_id, 1, GL_FALSE, &cam->viewMat[0][0]);
}

void WorldRenderer::light(const LightComponent& lc) const
{
  glUniform3fv(gl_a_pos_vec_id, 1, &lc.pos[0]);
  glDrawArrays(GL_TRIANGLES, 0, screen_quad.numVerts);
}

void WorldRenderer::blit() const
{
  glBindFramebuffer(GL_FRAMEBUFFER,0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,graphics->sWidth,graphics->sHeight);
  glUseProgram(gl_b_program_id);

  glBindVertexArray(gl_b_vert_array_id);
  glUniform1i(gl_b_tex_id, 4);
  glDrawArrays(GL_TRIANGLES, 0, screen_quad.numVerts);
}

WorldRenderer::~WorldRenderer()
{
  glBindFramebuffer(GL_FRAMEBUFFER, 0);

  //glDeleteRenderbuffers(1, &gl_g_fb_dep_buff_id); //alternative to depth2tex
  glDeleteTextures(1, &gl_g_fb_dep_tex_id);
  glDeleteTextures(1, &gl_g_fb_norm_tex_id);
  glDeleteTextures(1, &gl_g_fb_col_tex_id);
  glDeleteTextures(1, &gl_g_fb_pos_tex_id);
  glDeleteFramebuffers(1, &gl_g_fb_id);

  glDeleteTextures(1, &gl_a_fb_tex_id);
  glDeleteFramebuffers(1, &gl_a_fb_id);

  glDeleteVertexArrays(1, &gl_a_vert_array_id);
  glDeleteBuffers(1, &gl_a_pos_buff_id);
  glDeleteProgram(gl_a_program_id);

  glDeleteVertexArrays(1, &gl_g_vert_array_id);
  glDeleteBuffers(1, &gl_g_norm_buff_id);
  glDeleteBuffers(1, &gl_g_col_buff_id);
  glDeleteBuffers(1, &gl_g_pos_buff_id);
  glDeleteProgram(gl_g_program_id);

  glDeleteVertexArrays(1, &gl_b_vert_array_id);
  glDeleteBuffers(1, &gl_b_pos_buff_id);
  glDeleteProgram(gl_b_program_id);
}

