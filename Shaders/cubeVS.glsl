#version 330 core

layout(location = 0) in vec3 aPos; // for position
layout(location = 1) in vec3 aNorm; // for normal

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 FragPos;
out vec3 Normal;

void main() {
	FragPos = vec3(Model * vec4(aPos, 1.0));
	Normal = mat3(transpose(inverse(Model))) * aNorm;

	gl_Position = Projection * View * vec4(FragPos, 1.0);

}