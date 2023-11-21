#version 330 core

out vec4 FragCl;

uniform vec3 cubecl;

void main() {
	FragCl = vec4(cubecl, 1.0);
}