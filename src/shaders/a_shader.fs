#version 330 core

in vec2 UV;
out vec3 color;

uniform vec3 lightPosVec; //Non rotation affine

uniform sampler2D pos_tex;
uniform sampler2D col_tex;
uniform sampler2D norm_tex;
uniform samplerCubeShadow shadow_tex;
uniform sampler2D accum_tex; //the tex being drawn to

void main()
{
  vec3 lightToFragVec = texture(pos_tex, UV).xyz-lightPosVec;
  vec3 l2fabs = abs(lightToFragVec);
  float greatestMagnitudeOfLightToFragVec = max(l2fabs.x, max(l2fabs.y, l2fabs.z));
  float lightToFragDepth = ((100.0+0.1) / (100.0-0.1) - (2*100.0*0.1)/(100.0-0.1)/greatestMagnitudeOfLightToFragVec + 1.0) * 0.5;
  float directlight = texture(shadow_tex, vec4(normalize(lightToFragVec),lightToFragDepth));

  color = 
  texture(accum_tex, UV).xyz+                                        //current value
  (
  texture(col_tex, UV).xyz                                           //frag color
  *dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz) //dot product of angle of incidence of light to normal
  *(4+8*directlight)                                                 //shadow dampening/light amplification
  /max(0.000001,dot(lightToFragVec,lightToFragVec))                  //distance cutoff
  );
}

