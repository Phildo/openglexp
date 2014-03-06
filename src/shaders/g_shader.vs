#version 330 core

in vec3 vpos;
in vec3 vcol;

out vec3 fcol;
out vec3 fpos;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;
uniform float t;

void main()
{
  gl_Position = projMat * viewMat * modelMat * vec4(vpos,1.0);
  fpos = gl_Position.xyz;//(projMat * viewMat * modelMat * vec4(vpos,1.0)).xyz; 
  fcol = vcol;
}

