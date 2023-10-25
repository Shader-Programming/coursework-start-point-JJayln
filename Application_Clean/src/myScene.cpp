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
	glNamedBufferStorage(VBO, sizeof(float) * 18, vertexData, GL_DYNAMIC_STORAGE_BIT);// putting infomation in the created buffer

	glCreateVertexArrays(1, &VAO); // creating a VertexArray 
	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(float) * 6); // putting the buffer into the VA

	glEnableVertexArrayAttrib(VAO, 0);
	glEnableVertexArrayAttrib(VAO, 1);

	glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(VAO, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

	glVertexArrayAttribBinding(VAO, 0, 0);
	glVertexArrayAttribBinding(VAO, 1, 0);

}

void MyScene::update(float dt) {
	m_camera->update(dt);
	render();
}

void MyScene::render() {
	m_myShader->use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}