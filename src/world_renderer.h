#ifndef _WORLD_RENDERER_H_
#define _WORLD_RENDERER_H_

#include "renderer.h"
#include "world_component.h"

class Camera;

class WorldRenderer : public Renderer
{
  private:
    GLuint gl_program_id;

    GLuint gl_vert_array_id;

    GLuint gl_fb_id;
    GLuint gl_fb_tex_buff_id;
    GLuint gl_fb_depth_buff_id;

    GLuint gl_pos_buff_id;
    GLuint gl_color_buff_id;

    GLuint gl_proj_mat_id;
    GLuint gl_view_mat_id;
    GLuint gl_model_mat_id;

    GLuint gl_t_id;
    float t;
  public:
    WorldRenderer();
    ~WorldRenderer();

    void loadVertData(const WorldComponent& rc) const;
    void render(const Camera* cam, const WorldComponent& rc) const;
    void update();
};

#endif

