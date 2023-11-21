#include "Floor.h"


Floor::Floor(glm::vec3 col, float shine, float specStregnth) :
	m_colour(col),
	m_shine(shine),
	m_sStrength(specStregnth)
{
	makeVAO();
	resetTransform();
}

Floor::~Floor()
{

}

void Floor::setFloorMaterialValue(Shader* shader)
{
	shader->use();
	shader->setVec3("cubeCl", m_colour);
	shader->setFloat("shine", m_shine);
	shader->setFloat("specStrength", m_sStrength);
}

void Floor::makeVAO() {

	glCreateBuffers(1, &m_VBO);
	glNamedBufferStorage(m_VBO, sizeof(float) * vertexData.size(), vertexData.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateBuffers(1, &m_EBO);
	glNamedBufferStorage(m_EBO, sizeof(unsigned int) * FloorIndices.size(), FloorIndices.data(), GL_DYNAMIC_STORAGE_BIT);


	glCreateVertexArrays(1, &m_VAO);
	glVertexArrayVertexBuffer(m_VAO, 0, m_VBO, 0, sizeof(float) * 6);
	glVertexArrayElementBuffer(m_VAO, m_EBO);

	glEnableVertexArrayAttrib(m_VAO, 0);
	glEnableVertexArrayAttrib(m_VAO, 1);


	glVertexArrayAttribFormat(m_VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(m_VAO, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

	glVertexArrayAttribBinding(m_VAO, 0, 0);
	glVertexArrayAttribBinding(m_VAO, 1, 0);
}