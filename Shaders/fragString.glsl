#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 posInWS;

uniform vec3 viewPos;
uniform vec3 plightpos;
uniform vec3 plightcl;
uniform vec3 pAtt;

vec3 cubeCl = vec3(0.1, 0.2, 0.3);

vec3 lightCl = vec3(1.0f);
vec3 lightDr = vec3(-1.0f, -1.0f, 0.0f);
float ambientF = 0.5;

float shine = 16;
float specStrength = 1.5;

vec3 getPL();
vec3 getDrlight();

void main() {
    vec3 result = getDrlight();
    result += getPL();
    FragColor = vec4(result, 1.0);
}

vec3 getPL() {
    float distance = length(plightpos - posInWS);
    float attn = 1.0 / (pAtt.x + (pAtt.y * distance) + (pAtt.z * (distance * distance)));

    vec3 lightDir = normalize(plightpos - posInWS);

    vec3 ambient = cubeCl * lightCl * ambientF;

    vec3 n = normalize(Normal);
    float diffuseF = dot(n, -lightDir);
    diffuseF = max(diffuseF, 0.0f);
    vec3 diffuse = cubeCl * lightCl * diffuseF;

    vec3 viewDir = normalize(viewPos - posInWS);
    vec3 H = normalize(-lightDir + viewDir);
    float specLevel = dot(n, H);
    specLevel = max(specLevel, 0.0);
    specLevel = pow(specLevel, shine);
    vec3 specular = lightCl * specLevel * specStrength;

    diffuse = diffuse * attn;
    specular = specular * attn;
    return diffuse + specular;
}

vec3 getDrlight() {
    vec3 ambient = cubeCl * lightCl * ambientF;

    vec3 n = normalize(Normal);
    float diffuseF = dot(n, -lightDr);
    diffuseF = max(diffuseF, 0.0f);
    vec3 diffuse = cubeCl * lightCl * diffuseF;

    vec3 viewDir = normalize(viewPos - posInWS);
    vec3 H = normalize(-lightDr + viewDir);
    float specLevel = dot(n, H);
    specLevel = max(specLevel, 0.0);
    specLevel = pow(specLevel, shine);
    vec3 specular = lightCl * specLevel * specStrength;

    return ambient + diffuse + specular;
}
