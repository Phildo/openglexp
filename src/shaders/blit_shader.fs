#version 330 core

in vec2 UV;
layout(location = 0) out vec3 color;

uniform sampler2D tex;

void main()
{
  color = vec3(1.0,0.0,0.0);
  //color = vec3(UV.x, UV.y, 0.0);
  //color = texture(tex, UV).rgb
}

