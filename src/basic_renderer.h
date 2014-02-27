#ifndef _BASIC_RENDERER_H_
#define _BASIC_RENDERER_H_

#include "mygl.h"
#include "camera.h"
#include "render_component.h"

class BasicRenderer
{
  private:
    GLuint gl_program_id;

    GLuint gl_vert_array_id;

    GLuint gl_pos_buff_id;
    GLuint gl_color_buff_id;

    GLuint gl_proj_mat_id;
    GLuint gl_view_mat_id;
    GLuint gl_model_mat_id;

    glm::mat4 modelMat;

  public:
    BasicRenderer();
    ~BasicRenderer();

    void loadVertData(const RenderComponent& rc) const;
    void render(const Camera& cam, const RenderComponent& rc) const;
};

#endif

