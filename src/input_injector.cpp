#include "input_injector.h"
#include "input.h"
#include "gl_include.h"

InputInjector::InputInjector()
{
}

InputInjector::~InputInjector()
{
}

//This is probably the dumbest architecture I have ever designed
void InputInjector::inject(Input& i, InputPlanarComponent& ipc) const
{
  ipc.up = i.up;
  ipc.down = i.down;
  ipc.w = i.w;
  ipc.a = i.a;
  ipc.s = i.s;
  ipc.d = i.d;
}

