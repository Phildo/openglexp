#version 330 core

in vec2 UV;
out vec3 color;

uniform vec3 lightPosVec; //Non rotation affine
uniform mat4 lightViewMat; //Affine lightviewport
uniform mat4 lightProjMat; //non-affine lightviewport

uniform sampler2D pos_tex;
uniform sampler2D col_tex;
uniform sampler2D norm_tex;
uniform sampler2DShadow shadow_tex;
uniform sampler2D accum_tex; //the tex being drawn to

void main()
{
  float x = texture(pos_tex, UV).x-lightPosVec.x;
  float y = texture(pos_tex, UV).y-lightPosVec.y;
  float z = texture(pos_tex, UV).z-lightPosVec.z;
  float d = sqrt(x*x + y*y + z*z);

  vec4 posInLightClip = lightProjMat * lightViewMat * texture(pos_tex, UV);
  vec3 shadowSTR = (((posInLightClip/posInLightClip.w).xyz)+1)/2;

  if(texture(shadow_tex, shadowSTR) == 0.0)
    color = texture(accum_tex, UV).xyz+texture(col_tex, UV).xyz*(dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz)*0.5+0.5)*10/max(0.000001,d*d);
  else
    color = texture(accum_tex, UV).xyz+texture(col_tex, UV).xyz*(dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz)*0.5+0.5)*80/max(0.000001,d*d);
}

