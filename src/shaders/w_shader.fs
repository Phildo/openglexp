#version 330 core

in vec3 fcol;
in vec3 fpos;

out vec3 color;
out vec3 position;

void main()
{
  color = fcol;
  position = fpos;
}

