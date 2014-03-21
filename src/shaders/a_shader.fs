#version 330 core

in vec2 UV;
out vec3 color;

uniform vec3 lightPosVec; //Non rotation affine
uniform mat4 lightViewMat; //Affine lightviewport
uniform mat4 lightProjMat; //non-affine lightviewport

uniform sampler2D pos_tex;
uniform sampler2D col_tex;
uniform sampler2D norm_tex;
uniform samplerCubeShadow shadow_tex;
uniform sampler2D accum_tex; //the tex being drawn to

void main()
{
  float x = texture(pos_tex, UV).x-lightPosVec.x;
  float y = texture(pos_tex, UV).y-lightPosVec.y;
  float z = texture(pos_tex, UV).z-lightPosVec.z;
  float d = sqrt(x*x + y*y + z*z);

/*
  vec4 posInLightClip = lightProjMat * lightViewMat * texture(pos_tex, UV);
  vec3 shadowSTR = (((posInLightClip/posInLightClip.w).xyz)+1)/2;

  color = 
  texture(accum_tex, UV).xyz+                                        //current value
  texture(col_tex, UV).xyz                                           //frag color
  *dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz) //dot product of angle of incidence of light to normal
  *(4+15*texture(shadow_tex, shadowSTR))                             //shadow amplification
  /max(0.000001,d*d);                                                //distance cutoff
*/

  vec3 lightToFragVec = abs(texture(pos_tex, UV).xyz - lightPosVec);
  float greatestMagnitudeOfLightToFragVec = max(lightToFragVec.x, max(lightToFragVec.y, lightToFragVec.z));
  float lightToFragDepth = ((100.0+0.1) / (100.0-0.1) - (2*100.0*0.1)/(100.0-0.1)/greatestMagnitudeOfLightToFragVec + 1.0) * 0.5;
  float shadowed = texture(shadow_tex, vec4(normalize(texture(pos_tex, UV).xyz-lightPosVec),lightToFragDepth));

  color = 
  texture(accum_tex, UV).xyz+                                        //current value
  texture(col_tex, UV).xyz                                           //frag color
  *dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz) //dot product of angle of incidence of light to normal
  *(4+15*shadowed)                                                   //shadow amplification
  /max(0.000001,d*d);                                                //distance cutoff

}

