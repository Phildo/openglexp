#version 330 core

layout(location = 0) in vec3 vpos;
layout(location = 1) in vec3 vcol;

out vec3 fcol;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
  gl_Position = projMat * viewMat * modelMat * vec4(vpos,1.0);
  fcol = vcol;
}

