#include "basic_renderer.h"

GLuint loadShader(const char *vs_filename, const char *fs_filename)
{
  GLuint gl_program_id;
  GLuint gl_vs_id = glCreateShader(GL_VERTEX_SHADER);
  GLuint gl_fs_id = glCreateShader(GL_FRAGMENT_SHADER);

  std::string fileContents;
  FLATUtils::stringFromFile(vs_filename, fileContents);
  const char *vscp = fileContents.c_str();
  glShaderSource(gl_vs_id, 1, &vscp, NULL);
  glCompileShader(gl_vs_id);

  FLATUtils::stringFromFile(fs_filename, fileContents);
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
  gl_program_id = loadShader(vs_filename, fs_filename);
  
  //cpu Data
  modelMat = glm::mat4(1.0f);
  tri posBuffData[WIDTH*LENGTH*2];
  tri colorBuffData[WIDTH*LENGTH*2];

  //gen IDs
  glGenVertexArrays(1, &gl_vert_array_id);
  glGenBuffers(1, &gl_pos_buff_id);
  glGenBuffers(1, &gl_color_buff_id);
  gl_proj_mat_id  = glGetUniformLocation(gl_program_id, "projMat");
  gl_view_mat_id  = glGetUniformLocation(gl_program_id, "viewMat");
  gl_model_mat_id = glGetUniformLocation(gl_program_id, "modelMat");

  //populate VAO/buffers
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vert_array_id);

  GLuint attrib_0 = 0;
  glEnableVertexAttribArray(attrib_0);
  glBindBuffer(GL_ARRAY_BUFFER, gl_pos_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posBuffData), (GLfloat *)posBuffData, GL_STATIC_DRAW);
  glVertexAttribPointer(attrib_0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

  GLuint attrib_1 = 1;
  glEnableVertexAttribArray(attrib_1);
  glBindBuffer(GL_ARRAY_BUFFER, gl_color_buff_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colorBuffData), (GLfloat *)colorBuffData, GL_STATIC_DRAW);
  glVertexAttribPointer(attrib_1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
}

BasicRenderer::~BasicRenderer()
{
  glDeleteProgram(gl_program_id);
}

void BasicRenderer::render()
{
  glUseProgram(gl_program_id);
  glBindVertexArray(gl_vertArray_id);
}

