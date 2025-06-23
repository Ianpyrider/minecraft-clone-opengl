#version 330 core
out vec4 FragColor;

in vec4 pos;
in vec2 texCoord;

uniform sampler2D cube_texture;

void main()
{
   //FragColor = 2 * (pos + 0.25);
   FragColor = texture(cube_texture, texCoord);
}