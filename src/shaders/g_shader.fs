#version 330 core

in vec3 fpos;
in vec3 fcol;
in vec3 fnorm;

out vec3 position;
out vec3 color;
out vec3 normal;

void main()
{
  position = fpos;
  color = fcol;
  normal = fnorm;
}

