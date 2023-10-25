#pragma once
#include "Scene.h"
#include "Shader.h"

class MyScene : public Scene {

public:
	MyScene(GLFWwindow* window, InputHandler* H);
	~MyScene();
	void update(float dt) override;
private:
	unsigned int VBO, VAO;      //POS             RGB
	float vertexData[18] = { 0.5, 0.5, 0.0,  1.0, 0.0, 0.0,
						    -0.5, 0.5, 0.0,  0.0, 1.0, 0.0,
						    -0.5,-0.5, 0.0,  0.0, 0.0, 2.0};
	void makeVAO();
	void render();
	Shader* m_myShader;
};
