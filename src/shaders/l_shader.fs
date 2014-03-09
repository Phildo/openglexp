#version 330 core

in vec2 UV;
out vec3 color;

uniform vec3 posVec; //Non rotation affine
uniform mat4 viewMat; //Affine camera
uniform mat4 projMat; //non-affine camera

uniform sampler2D pos_tex;
uniform sampler2D col_tex;
uniform sampler2D norm_tex;
uniform sampler2D dep_tex;

void main()
{
  float x = texture(pos_tex, UV).x-posVec.x;
  float y = texture(pos_tex, UV).y-posVec.y;
  float z = texture(pos_tex, UV).z-posVec.z;
  float l = sqrt((x*x) + (y*y) + (z*z))/5;
  color = texture(pos_tex, UV).xyz;//vec3(0,0,0);
  //color = texture(col_tex, UV).rgb + texture(norm_tex, UV).rgb + (texture(dep_tex, UV).r-0.995)*500;
}

