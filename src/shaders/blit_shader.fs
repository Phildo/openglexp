#version 330 core

in vec2 UV;
out vec3 color;

uniform sampler2D col_tex;

void main()
{
  color = texture(col_tex, UV).rgb;
  //color = (texture(col_tex, UV).rgb-0.995)*500;
}

