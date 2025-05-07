#include"glprogram.h"
#include<GLFW/glfw3.h>
#include <vector>
#include"shaderLoader.h"

void glProgram::initialize() { //Set up assets (triangle mesh, textures, shaders)
	//Generate shaders
	m_shader = shaderLoader::createShaderProgram("default.vert", "default.frag");

	//TODO: Initialization steps


}

void glProgram::draw(GLFWwindow* window) { //Render scene (called every frame)
	//TODO: Draw steps


}

void glProgram::finalize() { //Free resources/memory, called at the end

}