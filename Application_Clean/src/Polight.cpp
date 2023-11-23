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

}



//void Polight::makeVAO()
//{
//    glGenVertexArrays(1, &m_VAO);
//    glBindVertexArray(m_VAO);
//
//    glGenBuffers(1, &m_VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//
//    float vertexData[] = {
//        3.0f, 0.0f, 0.0f, // light at the origin
//        -3.0f, 0.0f, 0.0f, // for the second light
//    };
//
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
//
//    // Set up vertex attributes (position)
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    m_vertexCount = 2;
//
//}