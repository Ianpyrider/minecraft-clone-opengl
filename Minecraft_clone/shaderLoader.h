#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

class shaderLoader
{
private:
	// Reads a text file and outputs a string with everything in the text file
	static std::string get_file_contents(const char* filename)
	{
		std::ifstream in(filename, std::ios::binary);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();
			return(contents);
		}
		throw(errno);
	}

public:
	// Read vertex and fragment files and load them into a shader
	static GLuint createShaderProgram(const char* vertex_file_path, const char* fragment_file_path) {
		std::string vertexCode = get_file_contents(vertex_file_path);
		std::string fragmentCode = get_file_contents(fragment_file_path);

		// Convert the shader source strings into character arrays
		const char* vertexShaderSource = vertexCode.c_str();
		const char* fragmentShaderSource = fragmentCode.c_str();

		//TODO: Return ID of fully initialized shader

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragShader);

		GLuint m_shader = glCreateProgram();
		glAttachShader(m_shader, vertexShader);
		glAttachShader(m_shader, fragShader);
		glLinkProgram(m_shader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);

		return m_shader;
	}
};

