#version 330 core

in vec3 fcol;
layout(location = 0) out vec3 color;

uniform float t;

void main()
{
  color = vec3(fcol.r*((sin(t)+1.0)/2.0),fcol.g*((sin(t+1.0)+1.0)/2.0),fcol.g*((sin(t+2.0)+1.0)/2.0));
}

