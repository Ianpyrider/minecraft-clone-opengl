#pragma once
#define GLFW_INCLUDE_NONE
#include<iostream>
#include<GLFW/glfw3.h>
#include"glprogram.h"


int main()
{
	// Initialize GLFW 3.3
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Use CORE PROFILE
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window	
	GLFWwindow* window = glfwCreateWindow(800, 800, "Minecraft Clone", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//Load glad, specify viewport
	gladLoadGL();
	glViewport(0, 0, 800, 800);
	
	//MAIN FUNCTIONS
	glProgram minecraftClone;

	minecraftClone.initialize();

	while (!glfwWindowShouldClose(window)) {
		minecraftClone.draw(window);
	}

	minecraftClone.finalize();
	
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}