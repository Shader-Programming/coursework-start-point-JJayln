#include "PLight.h"
#include "cube.h"

PoLight::PoLight(glm::vec3 colour, glm::vec3 position, glm::vec3 constants) :
	m_colour(colour),
	m_pos(position),
	m_const(constants)

{}

void PoLight::setLU(Shader* shader)
{
	shader->use();
	shader->setVec3("plightpos", m_pos);
	shader->setVec3("plightcl", m_colour);
	shader->setVec3("pAtt", m_const);

}
