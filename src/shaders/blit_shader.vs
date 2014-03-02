#version 330 core

layout(location = 0) in vec3 vpos;
out vec2 UV;

void main()
{
  gl_Position = vpos;
  uv = vpos.xy;
}

