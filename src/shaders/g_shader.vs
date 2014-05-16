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
uniform float time;

void main()
{
  vec3 off = vec3(
    sin((modelMatA[3].x+vpos.x*vpos.y+vpos.z)+time)/4,
    sin((vpos.x+modelMatA[3].y+vpos.y*vpos.z)+time)/4,
    sin((vpos.x+vpos.y*modelMatA[3].z+vpos.z)+time)/4
  );
  fpos = modelMatA * modelMatR * vec4(vpos+off, 1.0); //Affine position
  fcol = vcol;
  fnorm = (modelMatR * vec4(vnorm,1.0)).xyz;

  gl_Position = projMat * viewMat * fpos;
}

