#version 330 core

in vec3 vpos;
out vec2 UV;

void main()
{
  gl_Position = vec4(vpos,1.0);
  UV = (vpos.xy+1.0)/2.0;
}

