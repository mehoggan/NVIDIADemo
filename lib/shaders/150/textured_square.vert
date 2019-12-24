#version 150 core

in vec3 position;
in vec2 texcoord2d;

out vec2 TexCoord2d;

void main()
{
  TexCoord2d = texcoord2d;
  gl_Position = vec4(position, 1.0);
}
