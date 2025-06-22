#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Triangle
{
public:
	std::vector<GLfloat> generateShape() { return m_vertexData; }
	void updateParams();

private:
	std::vector<GLfloat> m_vertexData;

	void setVertexData();
	void addVec3(glm::vec3 v);
};

