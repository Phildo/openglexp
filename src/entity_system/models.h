#ifndef _MODELS_H_
#define _MODELS_H_

#include "model.h"

#define MAX_MODELS 6

//ECS_CONSTRUCT_MODEL_SIGNATURE_DEF_START
#define BILBOARD_MODEL 0
#define CUBE_MODEL 1
#define INV_CUBE_MODEL 2
#define LIGHT_CUBE_MODEL 3
#define SCREEN_QUAD_MODEL 4
#define TRIANGLE_MODEL 5
//ECS_CONSTRUCT_MODEL_SIGNATURE_DEF_END

namespace Models
{
    extern Model models[MAX_MODELS];
    void defineModels();
}

#endif

