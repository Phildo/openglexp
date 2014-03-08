#version 330 core

in vec3 fpos;
in vec3 fcol;
in vec3 fnorm;

layout (location = 0) out vec3 position;
layout (location = 1) out vec3 color;
layout (location = 2) out vec3 normal;

void main()
{
  position = fpos;
  color = fcol;
  normal = fnorm;
}

