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

  vec4 posInLightClip = lightProjMat * lightViewMat * texture(pos_tex, UV);
  vec2 UVInLightTex = (((posInLightClip/posInLightClip.w).xy)+1)/2;
  float ldep = 2.0 * (0.1*100) / ((100+0.1) - ((texture(shadow_tex, UVInLightTex).x*2)-1) * (100-0.1)); //supposedly the z of this fragment from the camera

  if(UVInLightTex.x > 1 || UVInLightTex.y > 1 || UVInLightTex.x < 0 || UVInLightTex.y < 0 || abs(ldep-d) > 1) 
    color = vec3(0,0,0);
  else
    color = texture(accum_tex, UV).xyz+texture(col_tex, UV).xyz*(dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz)*0.5+0.5)*40/max(0.000001,d*d);
}

