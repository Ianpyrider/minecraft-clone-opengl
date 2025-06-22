#version 330 core
out vec4 FragColor;

in vec4 pos;

void main()
{
   FragColor = 2 * (pos + 0.25);
}