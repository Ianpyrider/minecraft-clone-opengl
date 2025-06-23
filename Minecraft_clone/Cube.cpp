#include "Cube.h"
void Cube::setVertexData() {
	glm::vec3 ftl(- 0.5f, 0.5f, -0.5f);
	glm::vec3 fbl(-0.5f, -0.5f, -0.5f);
	glm::vec3 fbr(0.5f, -0.5f, -0.5f);
	glm::vec3 ftr(0.5f, 0.5f, -0.5f);
	glm::vec3 btl(-0.5f, 0.5f, 0.5f); 
	glm::vec3 bbl(-0.5f, -0.5f, 0.5f); 
	glm::vec3 bbr(0.5f, -0.5f, 0.5f); 
	glm::vec3 btr(0.5f, 0.5f, 0.5f);

	// Faces
	addFace(ftl, fbl, fbr, ftr, { 0.5f, 0.5f }); //Front
	addFace(btl, bbl, fbl, ftl, { 0.5f, 0.5f }); //Left
	addFace(btr, bbr, bbl, btl, { 0.5f, 0.5f }); //Back
	addFace(ftr, fbr, bbr, btr, { 0.5f, 0.5f }); //Right
	addFace(btl, ftl, ftr, btr, { 0.f, 0.5f }); //Top
	addFace(fbl, bbl, bbr, fbr, { 0.f, 0.f }); //Bottom
}

void Cube::addFace(glm::vec3 tl, glm::vec3 bl, glm::vec3 br, glm::vec3 tr, glm::vec2 adj_texture) {
	// FORMAT: color (vec3), texture (vec2)
	addVec3(tl);
	m_vertexData.push_back(0.f + adj_texture[0]);
	m_vertexData.push_back(0.5f + adj_texture[1]);

	addVec3(br);
	m_vertexData.push_back(0.5f + adj_texture[0]);
	m_vertexData.push_back(0.f + adj_texture[1]);

	addVec3(tr);
	m_vertexData.push_back(0.5f + adj_texture[0]);
	m_vertexData.push_back(0.5f + adj_texture[1]);


	addVec3(tl);
	m_vertexData.push_back(0.f + adj_texture[0]);
	m_vertexData.push_back(0.5f + adj_texture[1]);

	addVec3(bl);
	m_vertexData.push_back(0.f + adj_texture[0]);
	m_vertexData.push_back(0.f + adj_texture[1]);

	addVec3(br);
	m_vertexData.push_back(0.5f + adj_texture[0]);
	m_vertexData.push_back(0.f + adj_texture[1]);

	//m_vertices.push_back(v[0]);
	//m_vertices.push_back(v[2]);
	//m_vertices.push_back(v[3]);

	//m_vertices.push_back(v[0]);
	//m_vertices.push_back(v[1]);
	//m_vertices.push_back(v[2]);
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