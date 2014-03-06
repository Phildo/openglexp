#ifndef _WORLD_RENDERER_H_
#define _WORLD_RENDERER_H_

#include "renderer.h"
#include "world_component.h"

class Camera;

class WorldRenderer : public Renderer
{
  private:
    GLuint gl_fb_id;
    GLuint gl_fb_col_tex_id;
    GLuint gl_fb_pos_tex_id;
    GLuint gl_fb_dep_tex_id;
    //GLuint gl_fb_dep_buff_id;

    GLuint gl_g_program_id;
    GLuint gl_g_vert_array_id;
    GLuint gl_g_pos_buff_id;
    GLuint gl_g_color_buff_id;
    GLuint gl_g_pos_attrib_id;
    GLuint gl_g_col_attrib_id;
    GLuint gl_g_proj_mat_id;
    GLuint gl_g_view_mat_id;
    GLuint gl_g_model_mat_id;

    GLuint gl_l_program_id;
    GLuint gl_l_vert_array_id;
    GLuint gl_l_pos_buff_id;
    GLuint gl_l_pos_attrib_id;
    GLuint gl_l_col_tex_id;
    GLuint gl_l_pos_tex_id;
    GLuint gl_l_dep_tex_id;

    WorldComponent screen_quad; //really just a quad- outside of entity_system
  public:
    WorldRenderer(Graphics* g);
    ~WorldRenderer();

    void loadVertData(const WorldComponent& rc) const;
    void prepareForDraw();
    void render(const Camera* cam, const WorldComponent& rc) const;
    void light() const;
};

#endif

