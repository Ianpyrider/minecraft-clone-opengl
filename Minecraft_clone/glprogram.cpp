#include"glprogram.h"
#include<GLFW/glfw3.h>
#include <vector>
#include"shaderLoader.h"

void glProgram::initialize() { //Set up assets (triangle mesh, textures, shaders)
	//Generate shaders
	m_shader = shaderLoader::createShaderProgram("default.vert", "default.frag");

	//TODO: INIT FUNCTIONS


}

void glProgram::draw(GLFWwindow* window) { //Render scene (called every frame)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//TODO: DRAW FUNCTIONS



	//Not mentioned in the lab, keep this
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void glProgram::finalize() { //Free resources/memory, called at the end
	//TODO: FINALIZE FUNCTIONS


}