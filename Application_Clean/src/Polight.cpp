#include "Polight.h"
#include <iostream>

Polight::Polight(glm::vec3 colour, glm::vec3 position, glm::vec3 constant) : m_colour(colour), m_pos(position), m_const(constant)
{}


void Polight::setLU(Shader* shader)
{
	shader->use();
	shader->setVec3("plightpos", m_pos);
	shader->setVec3("plightcl", m_colour);
	shader->setVec3("pAtt", m_const);

	using std::cout;
	using std::cerr;
	using std::endl;

	cout << "Output message" << endl;
	cerr << "I AM WORKING" << endl;
}