#include <vector>
#include <memory>
#include "Shader.h"

class Floor {

public:
	Floor(glm::vec3 col, float shine, float specStrength);
	~Floor();
	void setFloorMaterialValue(Shader* shader);

	void setTransform(Shader* shader) { shader->setMat4("Model", m_transform); }
	void resetTransform() { m_transform = glm::mat4(1.0); }

	unsigned int& getVAO() { return m_VAO; }
	glm::mat4& getModelMatrix() { return m_transform; }
	unsigned int getIndicesCount() { return FloorIndices.size(); }


private:
	void makeVAO();
	//void setTransform(Shader* shader) const;

	unsigned int m_VBO, m_VAO, m_EBO;
	glm::mat4 m_transform;

	const float floorSize = 8.0f;
	const float floorLevel = -0.8f;

	float m_shine;
	float m_sStrength;
	glm::vec3 m_colour;

	//geometry data
	std::vector<float> vertexData = {
		-floorSize, floorLevel,  -floorSize,     0.0, 1.0, 0.0,
		floorSize, floorLevel,  -floorSize,     0.0, 1.0, 0.0,
		floorSize, floorLevel,   floorSize,     0.0, 1.0, 0.0,
		-floorSize, floorLevel,   floorSize,     0.0, 1.0, 0.0,
	};
	std::vector<unsigned int> FloorIndices = {
		3,2,1,
		3,1,0
	};
};