#pragma once
#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class TexMan {
public:

	TexMan();
	~TexMan() {}
	static unsigned int loadTex(char const* path);

};