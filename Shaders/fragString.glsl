#version 330 core

//uniform vec3 cl;
out vec4 FragColor;
//in vec3 vertexColour;

in vec3 Normal;

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
	diffuseF = max(diffuseF, 0.0);
	vec3 diffuse = cubeCl * lightCl * diffuseF;

	//Blinn Phong 
	vec3 viewDir = normalize(viewPos - posInWS);
	vec3 H = normaize(-lightDr + viewDir);
	float specLevel = dot(n, H);
	specLevel = max(specLevel, 0.0);
	specLevel = pow(specLevel, shine);
	vec3 specular = lightCl * specLevel * specStrength;

	
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0); // RGBA
	
}