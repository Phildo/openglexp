#version 330 core

in vec3 vpos;
in vec3 vcol;
in vec3 vnorm;

out vec4 fpos;
out vec3 fcol;
out vec3 fnorm;

uniform mat4 modelMatA; //Non rotation affine
uniform mat4 modelMatR; //Rotation
uniform mat4 viewMat; //Affine camera
uniform mat4 projMat; //non-affine camera

void main()
{
  gl_Position = projMat * viewMat * modelMatA * modelMatR * vec4(vpos,1.0);
  fpos = modelMatA * modelMatR * vec4(vpos, 1.0); //Affine position
  fcol = vcol;
  fnorm = (modelMatR * vec4(vnorm,1.0)).xyz;
}

