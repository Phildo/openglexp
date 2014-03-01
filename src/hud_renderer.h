#ifndef _HUD_RENDERER_H_
#define _HUD_RENDERER_H_

#include "renderer.h"
#include "hud_component.h"

class HUDRenderer : public Renderer
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
    HUDRenderer();
    ~HUDRenderer();

    void loadVertData(const HUDComponent& rc) const;
    void render(const HUDComponent& rc) const;
};

#endif

