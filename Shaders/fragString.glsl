#version 330 core

//uniform vec3 cl;
out vec4 FragColor;
//in vec3 vertexColour;

in vec3 Normal;
in vec3 posInWS;

uniform vec3 viewPos;

float shine = 16;
float specStrength = 1.5;

vec3 cubeCl = vec3(0.1, 0.2, 0.3);

vec3 lightCl = vec3(1.0f);
vec3 lightDr = vec3(-1.0f, -1.0f, 0.0f);

float ambientF = 0.5;

void main(){
	
	//ambient
	vec3 ambient = cubeCl * lightCl * ambientF;
	
	//diffuse
	vec3 n = normalize(Normal);
	float diffuseF = dot(n, -lightDr);
	diffuseF = max(diffuseF, 0.0f);
	vec3 diffuse = cubeCl * lightCl * diffuseF;

	//Blinn Phong
	
	vec3 viewDir = normalize(viewPos - posInWS);
	vec3 H = normalize(-lightDr + viewDir);
	float specLevel = dot(n, H);
	specLevel = max(specLevel, 0.0);
	specLevel = pow(specLevel, shine);
	vec3 specular = lightCl * specLevel * specStrength;

	
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
	
}