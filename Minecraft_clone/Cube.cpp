#include "Cube.h"
void Cube::setVertexData() {
	addVec3({ -0.25f, 0.25f, -0.25f }); //FTL
	addVec3({ -0.25f, -0.25f, -0.25f }); //FBL
	addVec3({ 0.25f, -0.25f, -0.25f }); //FBR
	addVec3({ 0.25f, 0.25f, -0.25f }); //FTR

	addVec3({ -0.25f, 0.25f, 0.25f }); //BTL
	addVec3({ -0.25f, -0.25f, 0.25f }); //BBL
	addVec3({ 0.25f, -0.25f, 0.25f }); //BBR
	addVec3({ 0.25f, 0.25f, 0.25f }); //BTR

	// Faces
	addFace({ 0, 1, 2, 3 }); //Front
	addFace({ 4, 5, 1, 0 }); //Left
	addFace({ 7, 6, 5, 4 }); //Back
	addFace({ 3, 2, 6, 7 }); //Right
	addFace({ 4, 0, 3, 7 }); //Top
	addFace({ 1, 5, 6, 2 }); //Bottom
}

void Cube::addFace(glm::vec4 v) {
	// V contains face indices in winding order
	m_vertices.push_back(v[0]);
	m_vertices.push_back(v[2]);
	m_vertices.push_back(v[3]);

	m_vertices.push_back(v[0]);
	m_vertices.push_back(v[1]);
	m_vertices.push_back(v[2]);
}

void Cube::addVec3(glm::vec3 v) {
	m_vertexData.push_back(v[0]);
	m_vertexData.push_back(v[1]);
	m_vertexData.push_back(v[2]);
}

void Cube::updateParams() {
	m_vertexData = std::vector<GLfloat>();
	setVertexData();
}