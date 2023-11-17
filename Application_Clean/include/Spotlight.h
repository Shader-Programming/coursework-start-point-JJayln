#pragma once
#include "Polight.h"
#include "Shader.h"

class Spotlight {
public:
	Spotlight(glm::vec3 colour, glm::vec3 position, glm::vec3 constants, glm::vec3 dir, glm::vec2 radii);
	~Spotlight() {};

	void setLU(Shader* shader);

	void setDir(glm::vec3 dir)  { m_dir = dir; }
	void setRadii(glm::vec2& r) { m_radii = r; }
	glm::vec2& getRadii() { return m_radii; }

private:
	glm::vec2 m_radii;
	glm::vec3 m_dir;
	glm::vec3 m_const;
	glm::vec3 m_pos;
	glm::vec3 m_colour;

};