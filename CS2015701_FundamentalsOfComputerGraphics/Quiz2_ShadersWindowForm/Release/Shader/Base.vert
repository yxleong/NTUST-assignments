#version 430

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

out vec3 VertexColor;

void main()
{
    gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(Position,1);
    VertexColor = Color;
}