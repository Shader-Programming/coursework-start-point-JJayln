#pragma once
#include "Scene.h"
#include "Shader.h"
#include "DrLight.h"
#include "cube.h"

class MyScene : public Scene {

public:
	MyScene(GLFWwindow* window, InputHandler* H);
	~MyScene();
	void update(float dt) override;
private:

	DrLight* m_DrLight;
	Shader* m_myShader;
	Cube* m_Cube;

	void render();
	
};
