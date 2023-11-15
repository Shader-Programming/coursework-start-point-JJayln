#pragma once
#include "myScene.h"


MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H) {
	m_camera = new FirstPersonCamera(glm::vec3());
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\shaders\\vertexString.glsl", "..\\shaders\\fragString.glsl");
	m_DrLight = new DrLight(glm::vec3(1.0), glm::vec3(-1.0f, -1.0f, 0.0f));
	m_DrLight->setLightUniforms(m_myShader);

	m_Cube = new cube(glm::vec3(0.1, 0.2, 0.3), 64, 16);
	m_Cube->setCubeMaterialValues(m_myShader);
}

MyScene::~MyScene()
{
	delete m_myShader;
	delete m_Cube;
	delete m_DrLight;
}



void MyScene::update(float dt) {
	m_camera->update(dt);
	render();
}

void MyScene::render() {
	
	m_myShader->use();
	m_myShader->setMat4("View", m_camera->getViewMatrix());
	m_myShader->setMat4("Projection", m_camera->getProjectionMatrix());
	m_myShader->setVec3("viewPos",m_camera->getPosition());

	

	glBindVertexArray(m_Cube->getVAO());
	m_Cube->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Cube->getIndicesCount(), GL_UNSIGNED_INT, 0);

}