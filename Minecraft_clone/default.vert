#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 transform;

out vec4 pos;

void main()
{
	pos = vec4(aPos, 1.f);
	gl_Position = transform * vec4(aPos, 1.f);
}