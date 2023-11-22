#version 330 core

layout(location = 0) in vec3 aPos; // for position
layout(location = 1) in vec3 aNorm; // for normal
layout(location = 2) in vec2 aUV; // for uv
//layout(location = 3) in ... aTang;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 Normal;
out vec3 posInWS;
out vec2 uv;

void main(){
	
	Normal = mat3(transpose(inverse(Model))) * aNorm;

	uv = aUV;

	vec4 worldSp = Model * vec4(aPos, 1.0);
	posInWS = worldSp.xyz;
	gl_Position = Projection * View * worldSp;
	
}