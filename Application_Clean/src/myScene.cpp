#pragma once
#include "myScene.h"


MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H) {
	m_camera = new FirstPersonCamera();
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\shaders\\vertexString.glsl", "..\\shaders\\fragString.glsl");
	m_DrLight = new DrLight(glm::vec3(1.0), glm::vec3(-1.0f, -1.0f, 0.0f));
	m_DrLight->setLightUniforms(m_myShader);
	makeVAO();



}

MyScene::~MyScene()
{
	delete m_myShader;
	delete m_camera;
}



void MyScene::update(float dt) {
	m_camera->update(dt);
	render();
}

void MyScene::render() {
	/*m_model = glm::mat4(1.0f);
	m_projection = m_camera->getProjectionMatrix();
	m_view = m_camera->getViewMatrix();*/

	m_myShader->use();

	m_myShader->setMat4("View", m_view);
	m_myShader->setMat4("Projection", m_projection);
	m_myShader->setVec3("viewPos",m_camera->getPosition());

	m_myShader->setMat4("Model", m_model);


	//m_myShader->setVec3("cl", glm::vec3(0.6, 0.4, 0.0));
	

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, cubeIndices.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 6);

	m_model = glm::translate(m_model, glm::vec3(5.0, 0.0, 0.0));
	//m_myShader->setVec3("cl", glm::vec3(0.1, 0.4, 0.0));
	

	m_myShader->setMat4("Model", m_model);

	glDrawElements(GL_TRIANGLES, vertexData.size(), GL_UNSIGNED_INT, 0);

	m_model = glm::translate(m_model, glm::vec3(3.0, 0.0, 0.0));
	//m_myShader->setVec3("cl", glm::vec3(0.2, 0.4, 0.6));
	m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.5), glm::vec3(1.0, 0.0, 0.0));

	m_myShader->setMat4("Model", m_model);

	glDrawElements(GL_TRIANGLES, vertexData.size(), GL_UNSIGNED_INT, 0);
}