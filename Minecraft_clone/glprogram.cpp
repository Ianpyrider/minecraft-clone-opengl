#include"glprogram.h"
#include<GLFW/glfw3.h>
#include <vector>
#include"shaderLoader.h"
#include"Triangle.h"
#include"Cube.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void glProgram::initialize() { //Set up assets (triangle mesh, textures, shaders)
	// Generate shaders
	m_shader = shaderLoader::createShaderProgram("default.vert", "default.frag");

	// GL settings
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Define objects
	Cube gen_cube;
	gen_cube.updateParams();

	std::vector<GLfloat> cube = gen_cube.getVertexData();

	// Generate vao/vbo
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	// Bind vao/vbo/ebo
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * cube.size(), cube.data(), GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * cube_indices.size(), cube_indices.data(), GL_STATIC_DRAW);

	// Set vertex attribute pointers
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));

	// Generate and bind texture
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("textures/textures.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		printf("Loaded texture successfully!");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	// Unbind vao/vbo/ebo
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void glProgram::draw(GLFWwindow* window) { //Render scene (called every frame)
	// Set bg color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Bind shader
	glUseProgram(m_shader);

	// Transform vertices
	glm::mat4 trans = glm::mat4(1.0f);
	//trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(0.0, 1.0, 0.0));
	trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.0f));

	unsigned int transformLoc = glGetUniformLocation(m_shader, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	// Bind vao and draw
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	// Unbind vao and shader
	glBindVertexArray(0);
	glUseProgram(0);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void glProgram::finalize() { //Free resources/memory, called at the end
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ebo);
	glDeleteVertexArrays(1, &m_vao);
}