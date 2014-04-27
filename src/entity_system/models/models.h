#ifndef _MODELS_H_
#define _MODELS_H_

#include "model.h"

#define MAX_MODELS 5

#define SCREEN_QUAD_MODEL 0
#define TRIANGLE_MODEL 1
#define BILBOARD_MODEL 2
#define CUBE_MODEL 3

namespace Models
{
    extern Model models[MAX_MODELS];
    void defineModels();
}

#endif

