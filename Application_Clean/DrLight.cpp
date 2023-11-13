#include "drLight.h"

DrLight::DrLight(glm::vec3 colour, glm::vec3 direction, float ambient) :
	Light(colour),
	m_direction(direction),
	m_ambientFactor(ambient)
{}

void DrLight::setLightUniforms(Shader* shader)
{
	shader->use();
	shader->setVec3("lightDr", m_direction);
	shader->setVec3("lightCl", m_colour);
	shader->setFloat("ambientFactor", m_ambientFactor);
}
