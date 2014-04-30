#include "models.h"

Model Models::models[MAX_MODELS];

void Models::defineModels()
{
  #include "models/screen_quad_model.h"
  #include "models/triangle_model.h"
  #include "models/bilboard_model.h"
  #include "models/cube_model.h"
  #include "models/inv_cube_model.h"
}

