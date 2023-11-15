#include "Cube.h"

Cube::Cube(glm::vec3 col, float shine, float specStrength): m_colour(col), m_shine(shine), m_sStrength(specStrength)
{
	makeVAO();
	resetTransform();
}


Cube::~Cube()
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
}

void Cube::setCubeMaterialValue(Shader* shader)
{
	shader->use();
	shader->setVec3("cubeColour", m_colour);
	shader->setFloat("shine", m_shine );
	shader->setFloat("specStrength", m_sStrength);
}

void Cube::rotate(float angle, glm::vec3 axis)
{
	m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.5), glm::vec3(1.0, 0.0, 0.0));
}

void Cube::scale(float scaleFactor, glm::vec3 axis)
{
	m_myShader->setMat4("Model", m_model);
}

void Cube::translate(glm::vec3 translation)
{
	m_model = glm::translate(m_model, glm::vec3(5.0, 0.0, 0.0));

	m_model = glm::translate(m_model, glm::vec3(3.0, 0.0, 0.0));


}

void Cube::makeVAO() {
	glCreateBuffers(1, &VBO); // number of buffers, name of buffer
	glNamedBufferStorage(VBO, sizeof(float) * vertexData.size(), vertexData.data(), GL_DYNAMIC_STORAGE_BIT);// putting infomation in the created buffer

	glCreateBuffers(1, &EBO); // creating an element buffer 
	glNamedBufferStorage(EBO, sizeof(unsigned int) * cubeIndices.size(), cubeIndices.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateVertexArrays(1, &VAO);
	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(float) * 6);
	glVertexArrayElementBuffer(VAO, EBO);

	glEnableVertexArrayAttrib(VAO, 0);
	glEnableVertexArrayAttrib(VAO, 1);

	glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(VAO, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

	glVertexArrayAttribBinding(VAO, 0, 0);
	glVertexArrayAttribBinding(VAO, 1, 0);

	/*GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		std::cerr << "OpenGL error (makeVAO): " << error << std::endl;
	}*/
}