#version 330 core

in vec3 vpos;

uniform mat4 modelMatA; //Non rotation affine
uniform mat4 modelMatR; //Rotation
uniform mat4 viewMat; //Affine camera
uniform mat4 projMat; //non-affine camera
uniform float wiggle;
uniform float time;

void main()
{
  vec3 off = vec3(
    sin((modelMatA[3].x+vpos.x*vpos.y+vpos.z)+time)/(4/wiggle),
    sin((vpos.x+modelMatA[3].y+vpos.y*vpos.z)+time)/(4/wiggle),
    sin((vpos.x+vpos.y*modelMatA[3].z+vpos.z)+time)/(4/wiggle)
  );
  gl_Position = projMat * viewMat * modelMatA * modelMatR * vec4(vpos+off,1.0);
}

