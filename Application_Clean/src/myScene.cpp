#pragma once
#include "myScene.h"


MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H) {
	m_camera = new FirstPersonCamera(glm::vec3());
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\Shaders\\vertexString.glsl", "..\\Shaders\\fragString.glsl");

	PLShaders = new Shader("..\\Shaders\\cubeVS.glsl", "..\\Shaders\\cubeFS.glsl");

	unsigned int cubeDiff = TexMan::loadTex("..\\Resources\\diffuseCube.jpg");
	unsigned int cubeSpec = TexMan::loadTex("..\\Resources\\specularCube.jpg");
	unsigned int cubeNorm = TexMan::loadTex("..\\Resources\\normalCube.jpg");

	m_DrLight = new DrLight(glm::vec3(1.0), glm::vec3(-1.0f, -1.0f, 0.0f));
	m_DrLight->setLightUniforms(m_myShader);

	m_polight = new Polight(glm::vec3(0.4, 0.0, 0.0), glm::vec3(-1.0, -0.4, 0.0), glm::vec3(1.0, 0.22, 0.02));
	m_polight->setLU(m_myShader);

	m_polight2 = new Polight(glm::vec3(0.4, 0.0, 0.0), glm::vec3(-2.0, -0.4, 0.0), glm::vec3(1.0, 0.22, 0.02));
	m_polight2->setLU(m_myShader);

	m_Cube = new Cube(cubeDiff, cubeSpec, cubeNorm, 16);
	m_Cube->setCubeMaterialValue(m_myShader);
	
	m_spotlight = new Spotlight(glm::vec3(0.5, 1.0, 0.0), glm::vec3(0.0, 3.0, 0.0), glm::vec3(1.0, 0.027, 0.0028), glm::vec3(0.0, -1.0, 0.0), glm::vec2(glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(17.5f))));
	m_spotlight->setLU(m_myShader);

	m_Floor = new Floor(glm::vec3(1.0, 0.0, 0.0), 64, 16);
	m_Floor->setFloorMaterialValue(m_myShader);
}
   


MyScene::~MyScene()
{
	delete m_myShader;
	delete m_Cube;
	delete m_DrLight;
	delete m_Floor;
	delete m_polight;
	delete m_polight2;
}


void MyScene::update(float dt) {
	m_camera->update(dt);
	render();
}

void MyScene::render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_myShader->use();
	//camera uniforms
	m_myShader->setMat4("View", m_camera->getViewMatrix());
	m_myShader->setMat4("Projection", m_camera->getProjectionMatrix());
	m_myShader->setVec3("viewPos", m_camera->getPosition());
	m_myShader->setVec3("slpos", m_camera->getPosition());
	m_myShader->setVec3("sldir", m_camera->getFront());

	//Cube 1
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

	//Floor
	glBindVertexArray(m_Floor->getVAO());
	m_Floor->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_Floor->getIndicesCount(), GL_UNSIGNED_INT, 0);
	m_Floor->resetTransform();
}
