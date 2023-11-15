#pragma once
#include <GLFW/glfw3.h>
#include "InputHandler.h"
#include "FPSCamera.h"
/*
Everything in scene goes here
I'd suggest using this as a base class and extending for specific scenes
*/

class Scene {

public:
	Scene(GLFWwindow* window, InputHandler* H) : m_window(window), m_handler(H) {}
	~Scene() {};
	virtual void update(float dt) {};
protected:
	GLFWwindow* m_window;
	InputHandler* m_handler;
	FirstPersonCamera* m_camera;
	

};
