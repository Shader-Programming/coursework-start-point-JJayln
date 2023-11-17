#pragma once
#include "myScene.h"


MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H) {
	m_camera = new FirstPersonCamera(glm::vec3());
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\shaders\\vertexString.glsl", "..\\shaders\\fragString.glsl");
	m_DrLight = new DrLight(glm::vec3(1.0), glm::vec3(-1.0f, -1.0f, 0.0f));
	m_DrLight->setLightUniforms(m_myShader);

	m_Cube = new Cube(glm::vec3(0.1, 0.2, 0.3), 64, 16);
	m_Cube->setCubeMaterialValue(m_myShader);

	m_polight = new Polight(glm::vec3(1.0, 0.0, 0.0), glm::vec3(-4.0, 0.0, 3.0), glm::vec3(1.0, 0.22, 0.02));
	m_polight->setLU(m_myShader);

	m_polight2 = new Polight(glm::vec3(1.0, 0.0, 0.0), glm::vec3(4.0, 0.0, 0.0), glm::vec3(1.0, 0.22, 0.02));
	m_polight2->setLU(m_myShader);

	m_Floor = new Floor(glm::vec3(1.0, 0.0, 0.0), 64, 16);
	m_Floor->setFloorMaterialValue(m_myShader);
}

MyScene::~MyScene()
{
	delete m_myShader;
	delete m_Cube;
	delete m_DrLight;
	delete m_polight;
	delete m_polight2;
	delete m_Floor;
}



void MyScene::update(float dt) {
	m_camera->update(dt);
	render();
}

void MyScene::render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_myShader->use();
	m_myShader->setMat4("View", m_camera->getViewMatrix());
	m_myShader->setMat4("Projection", m_camera->getProjectionMatrix());
	m_myShader->setVec3("viewPos", m_camera->getPosition());



	glBindVertexArray(m_Cube->getVAO());
	m_Cube->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Cube->getIndicesCount(), GL_UNSIGNED_INT, 0);

	//Cube 2
	m_Cube->translate(glm::vec3(5.0, 0.0, 0.0));
	m_Cube->rotate((float)(glfwGetTime() * 9.0), glm::vec3(1.0, 0.0, 0.0));
	m_Cube->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Cube->getIndicesCount(), GL_UNSIGNED_INT, 0);
	m_Cube->resetTransform();

	//Cube 3
	m_Cube->translate(glm::vec3(2.5, 0.0, 0.0));
	m_Cube->rotate((float)(glfwGetTime() * -9.0), glm::vec3(1.0, 0.0, 0.0));
	m_Cube->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Cube->getIndicesCount(), GL_UNSIGNED_INT, 0);
	m_Cube->resetTransform();

	//Cube 4
	m_Cube->translate(glm::vec3(0.0, -4.0, 0.0));
	/*m_Cube->scale(glm::vec3(2.0f));*/
	m_Cube->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Cube->getIndicesCount(), GL_UNSIGNED_INT, 0);
	m_Cube->resetTransform();

	//Floor
	glBindVertexArray(m_Floor->getVAO());
	m_Floor->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Floor->getIndicesCount(), GL_UNSIGNED_INT, 0);
	m_Floor->resetTransform();

	
}