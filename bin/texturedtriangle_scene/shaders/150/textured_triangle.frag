#version 150 core

in vec2 TexCoord2d;

out vec4 outColor;

uniform sampler2D tex;

void main()
{
  vec4 white = vec4(1.0, 1.0, 1.0, 1.0);
  outColor = white * texture(tex, TexCoord2d);
}
