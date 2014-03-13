#ifndef _WORLD_RENDERER_H_
#define _WORLD_RENDERER_H_

#include "renderer.h"
#include "geo_component.h"
#include "light_component.h"

class Camera;

class WorldRenderer : public Renderer
{
  private:
    //Geo
    GLuint gl_g_program_id;
    GLuint gl_g_vert_array_id;
    GLuint gl_g_pos_buff_id;
    GLuint gl_g_col_buff_id;
    GLuint gl_g_norm_buff_id;
    GLuint gl_g_pos_attrib_id;
    GLuint gl_g_col_attrib_id;
    GLuint gl_g_norm_attrib_id;
    GLuint gl_g_proj_mat_id;
    GLuint gl_g_view_mat_id;
    GLuint gl_g_model_mat_a_id;
    GLuint gl_g_model_mat_r_id;

    GLuint gl_g_fb_id;
    GLuint gl_g_fb_pos_tex_id;
    GLuint gl_g_fb_col_tex_id;
    GLuint gl_g_fb_norm_tex_id;
    GLuint gl_g_fb_dep_tex_id;

    //Shadow
    GLuint gl_s_program_id;
    GLuint gl_s_vert_array_id;
    GLuint gl_s_pos_buff_id;
    GLuint gl_s_pos_attrib_id;
    GLuint gl_s_proj_mat_id;
    GLuint gl_s_view_mat_id;
    GLuint gl_s_model_mat_a_id;
    GLuint gl_s_model_mat_r_id;

    GLuint gl_s_fb_id;
    GLuint gl_s_fb_dep_tex_id;

    //Accumulation
    GLuint gl_a_program_id;
    GLuint gl_a_vert_array_id;
    GLuint gl_a_pos_buff_id;
    GLuint gl_a_pos_attrib_id;
    GLuint gl_a_pos_tex_id;
    GLuint gl_a_col_tex_id;
    GLuint gl_a_norm_tex_id;
    GLuint gl_a_dep_tex_id;
    GLuint gl_a_tex_id;
    GLuint gl_a_proj_mat_id;
    GLuint gl_a_view_mat_id;
    GLuint gl_a_pos_vec_id;

    GLuint gl_a_fb_id;
    GLuint gl_a_fb_tex_id;

    //Blit
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
    void prepareForDraw(const Camera* cam) const;
    void render(const GeoComponent& gc) const;
    void prepareForLight(const Camera* cam) const;
    void light(const LightComponent& lc) const;
    void blit() const;
};

#endif

