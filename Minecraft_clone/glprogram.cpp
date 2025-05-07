#include"glprogram.h"
#include<GLFW/glfw3.h>
#include <vector>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

void glProgram::initialize() { //Set up assets (triangle mesh, textures, shaders)
	
}

void glProgram::draw(GLFWwindow* window) { //Render scene (called every frame)

}

void glProgram::finalize() { //Free resources/memory, called at the end

}