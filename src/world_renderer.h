#ifndef _WORLD_RENDERER_H_
#define _WORLD_RENDERER_H_

#include "mygl.h"
#include "camera.h"
#include "world_component.h"

class WorldRenderer
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
    WorldRenderer();
    ~WorldRenderer();

    void loadVertData(const WorldComponent& rc) const;
    void render(const Camera* cam, const WorldComponent& rc) const;
};

#endif

