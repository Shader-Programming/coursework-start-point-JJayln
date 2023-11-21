#pragma once
#include "Scene.h"
#include "Shader.h"
#include "DrLight.h"
#include "cube.h"
#include "Polight.h"
#include "Floor.h"
#include "Spotlight.h"
#include "TM.h"

class MyScene : public Scene {

public:
	MyScene(GLFWwindow* window, InputHandler* H);
	~MyScene();
	void update(float dt) override;
	void render();
	void renderPolightcubes();



private:

	DrLight* m_DrLight;
	Shader* m_myShader;
	Shader* PLShaders;
	Cube* m_Cube;
	Cube* PLCube;
	Polight* m_polight;
	Polight* m_polight2;
	Floor* m_Floor;
	Spotlight* m_spotlight;

	void renderPolight(Polight* polight);


};