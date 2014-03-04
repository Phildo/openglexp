#version 330 core

in vec2 UV;
out vec3 color;

uniform sampler2D col_tex;
uniform sampler2D dep_tex;

void main()
{
  color = texture(col_tex, UV).rgb+((texture(dep_tex, UV).r-0.995)*500);
  //color = (texture(dep_tex, UV).rgb-0.995)*500;
}

