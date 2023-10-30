#pragma once
#include "myScene.h"

MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H) {
	m_camera = new FirstPersonCamera();
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\shaders\\vertexString.glsl", "..\\shaders\\fragString.glsl");
	makeVAO();



}

MyScene::~MyScene()
{
	delete m_myShader;
	delete m_camera;
}

void MyScene::makeVAO() {
	glCreateBuffers(1, &VBO); // number of buffers, name of buffer
	glNamedBufferStorage(VBO, sizeof(float) * vertexData.size(), vertexData.data(), GL_DYNAMIC_STORAGE_BIT);// putting infomation in the created buffer

	glCreateBuffers(1, &EBO); // creating an element buffer 
	glNamedBufferStorage(EBO, sizeof(unsigned int) * cubeIndices.size(), cubeIndices.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateVertexArrays(1, &VAO);
	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(float) * 3);
	glVertexArrayElementBuffer(VAO, EBO);

	glEnableVertexArrayAttrib(VAO, 0);

	glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);

	glVertexArrayAttribBinding(VAO, 0, 0);

}

void MyScene::update(float dt) {
	m_camera->update(dt);
	render();
}

void MyScene::render() {
	m_model = glm::mat4(1.0f);
	m_projection = m_camera->getProjectionMatrix();
	m_view = m_camera->getViewMatrix();

	m_myShader->use();

	m_myShader->setMat4("View", m_view);
	m_myShader->setMat4("Projection", m_projection);
	m_myShader->setMat4("Model", m_model);

	m_myShader->setVec3("cl", glm::vec3(0.6, 0.4, 0.0));

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, cubeIndices.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 6);

	m_model = glm::translate(m_model, glm::vec3(5.0, 0.0, 0.0));
	m_myShader->setVec3("cl", glm::vec3(0.1, 0.4, 0.0));
	

	m_myShader->setMat4("Model", m_model);

	glDrawElements(GL_TRIANGLES, vertexData.size(), GL_UNSIGNED_INT, 0);

	m_model = glm::translate(m_model, glm::vec3(3.0, 0.0, 0.0));
	m_myShader->setVec3("cl", glm::vec3(0.2, 0.4, 0.6));
	m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.5), glm::vec3(1.0, 0.0, 0.0));

	m_myShader->setMat4("Model", m_model);

	glDrawElements(GL_TRIANGLES, vertexData.size(), GL_UNSIGNED_INT, 0);
}