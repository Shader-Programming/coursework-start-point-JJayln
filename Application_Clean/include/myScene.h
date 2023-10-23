#pragma once
#include "Scene.h"
#include "Shader.h"

class MyScene : public Scene {

public:
	MyScene(GLFWwindow* window, InputHandler* H);
	~MyScene();
	void update(float dt) override;
private:
	unsigned int VBO, VAO;
	float vertexData[9] = { 0.5, 0.5, 0.0,
						  -0.5, 0.5, 0.0,
						  -0.5, -0.5, 0.0 };
	void makeVAO();
	void render();
};
