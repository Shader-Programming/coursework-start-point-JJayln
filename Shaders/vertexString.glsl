#version 330 core

layout(location = 0) in vec3 aPos; // for position
//layout(location = 1) in vec3 aCol; // for color

//out vec3 vertexColour;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main(){
	
	//vertexColour = aCol;
	gl_Position = Projection * View * Model * vec4 (aPos, 1.0);
	
}