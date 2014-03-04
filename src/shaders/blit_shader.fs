#version 330 core

in vec2 UV;
layout(location = 0) out vec3 color;

uniform sampler2D tex;

void main()
{
  //color = texture(tex, UV).rgb;
  color = (texture(tex, UV).rgb-0.995)*500;
}

