#version 330 core

layout(location = 0) in vec3 vpos;
uniform mat4 ModelMat;
uniform mat4 ViewMat;
uniform mat4 ProjMat;

void main()
{
    gl_Position = ProjMat * ViewMat * ModelMat * vec4(vpos,1.0);
}

