#version 330 core

layout(location = 0) in vec3 aPos; // for position
layout(location = 1) in vec3 aCol; // for color

out vec3 vertexColour;

void main(){
	
	vertexColour = aCol;
	gl_Position = vec4(aPos, 1.0);
	
}