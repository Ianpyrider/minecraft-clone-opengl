#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Cube
{
public:
	std::vector<GLfloat> getVertexData() { return m_vertexData; }
	std::vector<int> getElementData() { return m_vertices; }
	void updateParams();

private:
	std::vector<GLfloat> m_vertexData;
	std::vector<int> m_vertices;

	void setVertexData();
	void addVec3(glm::vec3 v);
	void addFace(glm::vec4 v);
};
