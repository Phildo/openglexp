#ifndef _MODELS_H_
#define _MODELS_H_

#include "model.h"

#define MAX_MODELS 3

#define SCREEN_QUAD_MODEL 0
#define TRIANGLE_MODEL 1
#define BILBOARD_MODEL 2

class Models
{
  private:
  public:
    Models();
    Model models[MAX_MODELS];
};

#endif

