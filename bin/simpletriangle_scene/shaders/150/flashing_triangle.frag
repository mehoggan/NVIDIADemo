#version 150 core

out vec4 out_color;

uniform vec3 triangle_color;

void main()
{
  out_color = vec4(triangle_color, 1.0);
}
