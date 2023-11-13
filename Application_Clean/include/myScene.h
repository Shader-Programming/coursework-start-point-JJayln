#pragma once
#include "Scene.h"
#include "Shader.h"
#include "../drLight.h"
#include "../Cube.h"

class MyScene : public Scene {

public:
	MyScene(GLFWwindow* window, InputHandler* H);
	~MyScene();
	void update(float dt) override;
private:
	/*							//POS             RGB
	float vertexData[21] = { 0.5, 0.5, 0.0,  1.0, 0.0, 0.0,
						     0.5,-0.5, 0.0,  0.0, 1.0, 0.0,
						    -0.5,-0.5, 0.0,  0.0, 0.0, 2.0,
							-0.5, 0.5, 0.0};
	*/

	DrLight* m_DrLight;
	Shader* m_myShader;
	Cube* m_Cube;

	//unsigned int VBO, VAO, EBO;
	//glm::mat4 m_model, m_view, m_projection;

	/*std::vector<float> vertexData = {//  xyz
									// back
									-0.5f, -0.5f, -0.5f,
									 0.5f, -0.5f, -0.5f,
									 0.5f,  0.5f, -0.5f,
									-0.5f,  0.5f, -0.5f,
									// front
									-0.5f, -0.5f,  0.5f,
									 0.5f, -0.5f,  0.5f,
									 0.5f,  0.5f,  0.5f,
									-0.5f,  0.5f,  0.5f,
									// left
									-0.5f,  0.5f,  0.5f,
									-0.5f,  0.5f, -0.5f,
									-0.5f, -0.5f, -0.5f,
									-0.5f, -0.5f,  0.5f,
									// right
									 0.5f,  0.5f,  0.5f,
									 0.5f,  0.5f, -0.5f,
									 0.5f, -0.5f, -0.5f,
									 0.5f, -0.5f,  0.5f,
									 // bottom
									 -0.5f, -0.5f, -0.5f,
									  0.5f, -0.5f, -0.5f,
									  0.5f, -0.5f,  0.5f,
									 -0.5f, -0.5f,  0.5f,
									 // top
									 -0.5f,  0.5f, -0.5f,
									  0.5f,  0.5f, -0.5f,
									  0.5f,  0.5f,  0.5f,
									 -0.5f,  0.5f,  0.5f};*/

	/*std::vector<float> vertexData = {
		//  xyz, normal
		// back
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		// front
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		// left
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		// right
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 // bottom
		 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 // top
		 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		  0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f
	};*/

	void render();
	
};
