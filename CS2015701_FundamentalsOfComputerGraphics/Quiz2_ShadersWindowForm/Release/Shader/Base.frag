#version 430

in vec3 VertexColor;
out vec4 outColor;

void main()
{
    outColor = vec4(VertexColor,1.0);
}