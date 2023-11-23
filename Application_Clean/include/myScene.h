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
	void render( );



private:

	// Pointers 
	DrLight* m_DrLight;
	Shader* m_myShader;
	Shader* PLShaders;
	Polight* m_polight;
	Cube* m_Cube;
	Cube* PLCube;
	Floor* m_Floor;
	Spotlight* m_spotlight;

};