#version 330 core

layout(location = 0) in vec3 aPos; // for position
layout(location = 1) in vec3 aNorm; // for normal

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 Normal;
out vec3 posInWS

void main(){
	
	Normal = aNorm;

	vec4 worldSp = model * vec4(aPos, 1.0);
	posInWS = worldSp.xyz;
	gl_Position = Projection * View * worldSp;
	
}