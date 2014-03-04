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
    GLuint gl_fb_depth_tex_id;
    //GLuint gl_fb_depth_buff_id;

    GLuint gl_draw_program_id;
    GLuint gl_draw_vert_array_id;
    GLuint gl_draw_pos_buff_id;
    GLuint gl_draw_color_buff_id;
    GLuint gl_draw_proj_mat_id;
    GLuint gl_draw_view_mat_id;
    GLuint gl_draw_model_mat_id;
    GLuint gl_draw_t_id;

    GLuint gl_blit_program_id;
    GLuint gl_blit_vert_array_id;
    GLuint gl_blit_pos_buff_id;
    GLuint gl_blit_tex_id;

    float t;
    WorldComponent screen_quad; //really just a quad- outside of entity_system
  public:
    WorldRenderer(Graphics* g);
    ~WorldRenderer();

    void loadVertData(const WorldComponent& rc) const;
    void prepareForDraw();
    void render(const Camera* cam, const WorldComponent& rc) const;
    void blit() const;
    void update();
};

#endif

