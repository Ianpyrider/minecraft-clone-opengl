#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 transform;

out vec4 pos;
out vec2 texCoord;

void main()
{
	pos = vec4(aPos, 1.f);
	gl_Position = transform * vec4(aPos, 1.f);
	texCoord = aTexCoord;
}