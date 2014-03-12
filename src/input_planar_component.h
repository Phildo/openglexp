#ifndef _INPUT_PLANAR_COMPONENT_H_
#define _INPUT_PLANAR_COMPONENT_H_

#include "gl_include.h"

class InputPlanarComponent
{
  private:
  public:
    InputPlanarComponent();
    ~InputPlanarComponent();

    int entityIndex;

    bool up;
    bool down;
    bool w;
    bool a;
    bool s;
    bool d;
};

#endif

