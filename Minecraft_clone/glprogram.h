#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

class glProgram
{
public:
	void initialize();
	void draw(GLFWwindow* window);
	void finalize();

private:
	GLuint m_shader; // Id of Shader
	GLuint m_vbo;    // Stores id of VBO
	GLuint m_vao;    // Stores id of VAO
};
#endif