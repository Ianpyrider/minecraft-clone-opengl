#include "Triangle.h"

void Triangle::setVertexData() {
	addVec3({ 0.f, 1.f, 0.f }); //V1
	addVec3({ 1.f, 0.f, 0.f }); //C1
	addVec3({ 0.f, 0.f, 0.f }); //V2
	addVec3({ 0.f, 1.f, 0.f }); //C2
	addVec3({ 1.f, 0.f, 0.f }); //V3
	addVec3({ 0.f, 0.f, 1.f }); //C3
}

void Triangle::addVec3(glm::vec3 v) {
	m_vertexData.push_back(v[0]);
	m_vertexData.push_back(v[1]);
	m_vertexData.push_back(v[2]);
}

void Triangle::updateParams() {
	m_vertexData = std::vector<GLfloat>();
	setVertexData();
}