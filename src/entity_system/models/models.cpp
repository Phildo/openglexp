#include "models.h"

Model Models::models[MAX_MODELS];

void Models::defineModels()
{
  #include "screen_quad_model.h"
  #include "triangle_model.h"
  #include "bilboard_model.h"
  #include "cube_model.h"
  #include "inv_cube_model.h"
}

