#pragma once
#include "drLight.h"
#include "Light.h"
#include "Shader.h"

class PoLight : public Light {

public:
	PoLight(glm::vec3 colour, glm::vec3 position, glm::vec3 constants);
	~PoLight() {};

	void setLU(Shader* shader);

	void setConstants(glm::vec3& constants) { m_const = constants; }
	void setPosition(glm::vec3& pos) { m_pos = pos; }

	glm::vec3& getPos() { return m_pos; }
	glm::vec3& getConst() { return m_const; }

protected:
	glm::vec3 m_const;
	glm::vec3 m_pos;
	glm::vec3 m_colour;
};