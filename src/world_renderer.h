#ifndef _WORLD_RENDERER_H_
#define _WORLD_RENDERER_H_

#include "renderer.h"
#include <glm/glm.hpp>

class CameraComponent;
class GeometryComponent;
class LightComponent;
class Model;

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
    GLuint gl_g_fb_dep_buff_id;

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
    GLuint gl_s_fb_cube_dep_tex_id;

    //Accumulation
    GLuint gl_a_program_id;
    GLuint gl_a_vert_array_id;
    GLuint gl_a_pos_buff_id;
    GLuint gl_a_pos_attrib_id;
    GLuint gl_a_pos_tex_id;
    GLuint gl_a_col_tex_id;
    GLuint gl_a_norm_tex_id;
    GLuint gl_a_shadow_tex_id;
    GLuint gl_a_tex_id;
    GLuint gl_a_light_pos_vec_id;

    GLuint gl_a_fb_id;
    GLuint gl_a_fb_tex_id;

    //Blit
    GLuint gl_b_program_id;
    GLuint gl_b_vert_array_id;
    GLuint gl_b_pos_buff_id;
    GLuint gl_b_pos_attrib_id;
    GLuint gl_b_tex_id;

    //Projections for 6 sided shadow cube
    glm::mat4 shadowProjMat; 
    glm::mat4 shadowViewMats[6];

  public:
    WorldRenderer();
    ~WorldRenderer();

    void clear();

    void prepareForGeo(const CameraComponent& cam) const;
    void loadModelVertData(const Model& m) const;
    void renderGeo(const GeometryComponent& gc) const;

    void prepareForShadow(const LightComponent& lc);
    void loadShadowVertData(const Model& m) const;
    void prepareForShadowOrientation(const GLuint orientation) const;
    void renderShadow(const GeometryComponent& gc) const;

    void prepareForLight() const;
    void light(const LightComponent& lc) const;

    void blit() const;
};

#endif

