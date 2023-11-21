#include "Cube.h"


Cube::Cube(unsigned int diffTexture, unsigned int specTexture, float shine): m_diffTex(diffTexture), m_specTex(specTexture), m_shine(shine)
{
	makeVAO();
	resetTransform();
}

Cube::~Cube()
{

}

void Cube::setCubeMaterialValue(Shader* shader)
{
	shader->use();
	//shader->setVec3("cubeCl", m_colour);
	shader->setFloat("shine", m_shine);
	//shader->setFloat("specStrength", m_sStrength);
	shader->setInt("diffuseMap", 0);
	shader->setInt("specularMap", 1);

	glBindTextureUnit(0, m_diffTex);
	glBindTextureUnit(1, m_specTex);
}

void Cube::rotate(float angle, glm::vec3 axis)
{
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
	m_transform = rotationMatrix * m_transform;
}

void Cube::scale(float scaleFactor, glm::vec3 axis)
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scaleFactor));
	m_transform = scaleMatrix * m_transform;
}

void Cube::translate(glm::vec3 translation)
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), translation);
	m_transform = translationMatrix * m_transform;
}

void Cube::makeVAO() {

	glCreateBuffers(1, &m_VBO);
	glNamedBufferStorage(m_VBO, sizeof(float) * vertexData.size(), vertexData.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateBuffers(1, &m_EBO);
	glNamedBufferStorage(m_EBO, sizeof(unsigned int) * cubeIndices.size(), cubeIndices.data(), GL_DYNAMIC_STORAGE_BIT);


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

/*void Cube::setTransform(Shader* shader) const
{
	glm::mat4 model = glm::mat4(1.0f);
	shader->setMat4("model", model);
}
*/