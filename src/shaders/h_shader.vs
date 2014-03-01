#version 330 core

layout(location = 0) in vec3 vpos;
layout(location = 1) in vec3 vcol;

out vec3 fcol;

uniform mat4 viewMat;

void main()
{
  gl_Position = viewMat * vec4(vpos,1.0);
  fcol = vcol;
}

