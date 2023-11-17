#pragma once
#include "Light.h"
#include "Shader.h"


class Polight {

public:
	Polight(glm::vec3 colour, glm::vec3 position, glm::vec3 constants);
	~Polight() {};

	void setLU(Shader* shader);

	void setConstants(glm::vec3& constants) { m_const = constants; }
	void setPosition(glm::vec3& pos) { m_pos = pos; }

	unsigned int getVertexCount() const { return m_vertexCount; }
	unsigned int getVAO() const { return m_VAO; }
	glm::vec3& getPos() { return m_pos; }
	glm::vec3& getConst() { return m_const; }

private:

	unsigned int m_VBO, m_VAO;
	glm::vec3 m_const;
	glm::vec3 m_pos;
	glm::vec3 m_colour;
	unsigned int m_vertexCount;

	void makeVAO();
};