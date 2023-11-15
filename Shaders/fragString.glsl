# version 330 core

out vec4 FragColor;
//in vec3 vertexColour;

in vec3 normals;

in vec3 posInWS;

uniform vec3 viewPos;

vec3 getDirectionLight();

vec3 n = normalize(normals);
vec3 viewDir = normalize(viewPos - posInWS);

vec3 getDirectionLight();

uniform vec3 cubeColour;

uniform vec3 lightColour;
uniform vec3 lightDirection;
uniform float ambientFactor;
uniform float shine;
uniform float specStrength;

in vec3 posInWS;

uniform vec3 viewPos;

vec3 n = normalize(normals);
vec3 viewDir = normalize(viewPos - posInWS);

vec3 getDirectionLight();

void main() {
	vec3 result = getDirectionLight();
	FragColor = vec4(result, 1.0); // RGA

}

vec3 getDirectionLight()
{
	//ambient
	vec3 ambient = cubeColour * lightColour * ambientFactor;

	//diffused
	float diffuseFactor = dot(n, -lightDirection);
	diffuseFactor = max(diffuseFactor, 0.0f);
	vec3 diffuse = cubeColour * lightColour * diffuseFactor;

	//Blinn Phong speculer
	vec3 H = normalize(-lightDirection + viewDir);
	float specLevel = dot(n, H);
	specLevel = max(specLevel, 0.0);
	specLevel = pow(specLevel, shine);
	vec3 specular = lightColour * specLevel * specStrength;


	return ambient + diffuse + specular;
}