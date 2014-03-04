#version 330 core

in vec3 vpos;
in vec3 vcol;

out vec3 fcol;

uniform mat4 viewMat;

void main()
{
  gl_Position = viewMat * vec4(vpos,1.0);
  fcol = vcol;
}

