#version 150 core

out vec4 outColor;

void main()
{
    vec3 color = vec3(1.0, 1.0, 1.0);
    outColor = vec4(color, 1.0);
}
