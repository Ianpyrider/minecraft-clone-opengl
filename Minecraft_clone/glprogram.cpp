#include"glprogram.h"
#include<GLFW/glfw3.h>

void glProgram::initialize(GLFWwindow* window) { //Set up assets (triangle mesh, textures, shaders)
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


}

void glProgram::draw() { //Render scene (called every frame)
	glfwPollEvents();
}

void glProgram::finalize() { //Free resources/memory, called at the end

}