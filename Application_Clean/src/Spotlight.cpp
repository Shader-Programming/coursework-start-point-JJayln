#include "Spotlight.h"
#include <iostream>

Spotlight::Spotlight(glm::vec3 colour, glm::vec3 position, glm::vec3 constants, glm::vec3 dir, glm::vec2 radii) : m_colour(colour), m_pos(position), m_const(constants), m_dir (dir), m_radii (radii)
{}

void Spotlight::setLU(Shader* shader)
{
    
    shader->use(); 

    shader->setVec3("spotlightColor", m_colour);
    shader->setVec3("spotlightPosition", m_pos);
    shader->setVec3("spotlightConstants", m_const);
    shader->setVec3("spotlightDirection", m_dir);
    shader->setVec2("spotlightRadii", m_radii);

    // Debugging output
    using std::cout;
    using std::cerr;
    using std::endl;

    cout << "Spotlight uniforms set successfully." << std::endl;
    cerr << "I AM WORKING" << endl;
}
