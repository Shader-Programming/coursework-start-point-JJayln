#version 330 core

layout(location = 0) in vec3 aPos; // for position
layout(location = 1) in vec3 aNorm; // for normal
layout(location = 2) in vec2 aUV; // for uv
layout(location = 3) in vec3 aTan;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 Normal;
out vec3 posInWS;
out vec2 uv;
out mat3 TBN;

void main(){
	
	Normal = mat3(transpose(inverse(Model))) * aNorm;

	uv = aUV;

	vec4 worldSp = Model * vec4(aPos, 1.0);
	posInWS = worldSp.xyz;
	gl_Position = Projection * View * worldSp;
	
	vec3 T = (Model * vec4(aTan, 0.0)).xyz;
	vec3 N = Normal;
	vec3 B = normalize(cross(T, N));
	TBN = mat3(T, B, N);
}