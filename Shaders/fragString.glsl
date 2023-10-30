#version 330 core

uniform vec3 cl;
out vec4 FragColor;
//in vec3 vertexColour;

void main(){
	
	FragColor = vec4( cl, 1.0); // RGBA
	
}