#ifndef _INPUT_INJECTOR_H_
#define _INPUT_INJECTOR_H_

#include "input_planar_component.h"

class Input;

class InputInjector
{
  private:
  public:
    InputInjector();
    ~InputInjector();

    void inject(Input& i, InputPlanarComponent& ipc) const;
};

#endif

