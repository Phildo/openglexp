#ifndef _WORLD_RENDERER_H_
#define _WORLD_RENDERER_H_

#include "renderer.h"
#include "geo_component.h"

class Camera;

class WorldRenderer : public Renderer
{
  private:
    GLuint gl_g_program_id;
    GLuint gl_g_vert_array_id;
    GLuint gl_g_pos_buff_id;
    GLuint gl_g_col_buff_id;
    GLuint gl_g_pos_attrib_id;
    GLuint gl_g_col_attrib_id;
    GLuint gl_g_proj_mat_id;
    GLuint gl_g_view_mat_id;
    GLuint gl_g_model_mat_id;

    GLuint gl_g_fb_id;
    GLuint gl_g_fb_col_tex_id;
    GLuint gl_g_fb_pos_tex_id;
    GLuint gl_g_fb_dep_tex_id;
    //GLuint gl_g_fb_dep_buff_id;

    GLuint gl_l_program_id;
    GLuint gl_l_vert_array_id;
    GLuint gl_l_pos_buff_id;
    GLuint gl_l_pos_attrib_id;
    GLuint gl_l_col_tex_id;
    GLuint gl_l_pos_tex_id;
    GLuint gl_l_dep_tex_id;

    GLuint gl_l_fb_id;
    GLuint gl_l_fb_tex_id;

    GLuint gl_b_program_id;
    GLuint gl_b_vert_array_id;
    GLuint gl_b_pos_buff_id;
    GLuint gl_b_pos_attrib_id;
    GLuint gl_b_tex_id;

    GeoComponent screen_quad; //really just a quad- outside of entity_system
  public:
    WorldRenderer(Graphics* g);
    ~WorldRenderer();

    void loadVertData(const GeoComponent& gc) const;
    void prepareForDraw() const;
    void render(const Camera* cam, const GeoComponent& gc) const;
    void prepareForLight() const;
    void light() const;
    void blit() const;
};

#endif

