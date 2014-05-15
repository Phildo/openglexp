#include "models.h"

Model Models::models[MAX_MODELS];

void Models::defineModels()
{
//ECS_CONSTRUCT_MODEL_INCLUDE_START
#include "models/bilboard_model.h"
#include "models/cube_model.h"
#include "models/inv_cube_model.h"
#include "models/light_cube_model.h"
#include "models/screen_quad_model.h"
#include "models/triangle_model.h"
//ECS_CONSTRUCT_MODEL_INCLUDE_END
}

