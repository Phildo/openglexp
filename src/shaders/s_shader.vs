#version 330 core

in vec3 vpos;

uniform mat4 modelMatA; //Non rotation affine
uniform mat4 modelMatR; //Rotation
uniform mat4 viewMat; //Affine camera
uniform mat4 projMat; //non-affine camera

void main()
{
  gl_Position = projMat * viewMat * modelMatA * modelMatR * vec4(vpos,1.0);
}

