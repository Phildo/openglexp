#version 330 core

in vec2 UV;
out vec3 color;

uniform mat4 viewMat; //Affine camera
uniform mat4 projMat; //non-affine camera
uniform vec3 lightPosVec; //Non rotation affine
uniform mat4 lightViewMat; //Affine lightviewport
uniform mat4 lightProjMat; //non-affine lightviewport

uniform sampler2D pos_tex;
uniform sampler2D col_tex;
uniform sampler2D norm_tex;
uniform sampler2D dep_tex;
uniform sampler2D shadow_tex;
uniform sampler2D accum_tex; //the tex being drawn to

void main()
{
  float x = texture(pos_tex, UV).x-lightPosVec.x;
  float y = texture(pos_tex, UV).y-lightPosVec.y;
  float z = texture(pos_tex, UV).z-lightPosVec.z;
  float d = sqrt(x*x + y*y + z*z);
  color = texture(accum_tex, UV).xyz+texture(col_tex, UV).xyz*(dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz)*0.5+0.5)*20/max(0.000001,d*d);


  //fragment pos in the shadow depth tex
  vec4 fpos = lightProjMat * lightViewMat * vec4(texture(pos_tex, UV).xyz,1.0);
  vec2 fuv = (fpos.xy+1)/2;

  //color = texture(pos_tex, UV).xyz;
  //color = ((texture(dep_tex, UV)-0.995)*500).rgb;
  //color = texture(col_tex, UV).rgb + texture(norm_tex, UV).rgb + (texture(dep_tex, UV).r-0.995)*500;
}

