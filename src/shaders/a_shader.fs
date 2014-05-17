#version 330 core

in vec2 UV;
out vec3 color;

uniform vec3 lightPosVec;
uniform float lightIntensity;

uniform sampler2D pos_tex;
uniform sampler2D col_tex;
uniform sampler2D norm_tex;
uniform samplerCubeShadow shadow_tex;
uniform sampler2D accum_tex; //the tex being drawn to

void main()
{
  vec3 lightToFragVec = texture(pos_tex, UV).xyz-lightPosVec;
  if(length(lightToFragVec) > 100) { color = texture(accum_tex, UV).xyz; return; }

  vec3 l2fabs = abs(lightToFragVec);
  float greatestMagnitudeOfLightToFragVec = max(l2fabs.x, max(l2fabs.y, l2fabs.z));
  float lightToFragDepth = ((100.0+1.0) / (100.0-1.0) - (2*100.0*1.0)/(100.0-1.0)/greatestMagnitudeOfLightToFragVec + 1.0) * 0.5;
  float directlight = texture(shadow_tex, vec4(normalize(lightToFragVec),lightToFragDepth));

  vec3 contribution =
    texture(col_tex, UV).xyz                                           //frag color
    *dot(lightPosVec-texture(pos_tex,UV).xyz,texture(norm_tex,UV).xyz) //dot product of angle of incidence of light to normal
    *(2+lightIntensity*directlight)                                    //shadow dampening/light amplification
    /max(0.000001,dot(lightToFragVec,lightToFragVec))                  //distance cutoff
  ;

  //if(length(contribution) < 0.01) { color = texture(accum_tex, UV).xyz; return; }

  color = texture(accum_tex, UV).xyz + max(contribution, vec3(0,0,0));
}

