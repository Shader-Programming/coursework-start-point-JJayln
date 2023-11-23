#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 posInWS;
in vec2 uv;
in mat3 TBN;

uniform vec3 viewPos;

// DL Uniforms
uniform vec3 lightCl = vec3(1.0f);
uniform vec3 lightDr = vec3(-1.0f, -1.0f, 0.0f);
uniform float ambientF = 0.5;

// PL Uniforms
uniform vec3 plightpos;
uniform vec3 plightcl;

// SL Uniforms
uniform vec3 slpos;
uniform vec3 slcol;
uniform vec3 sAtt;
uniform vec3 sldir;
uniform vec3 sRadii;

// Material Properties
uniform sampler2D diffMap;
uniform sampler2D specMap;
uniform sampler2D normMap;
uniform float shine;

vec3 cubeCl = vec3(0.1, 0.2, 0.3);
vec3 n;

float pAttx = 1;
float pAtty = 0.09;
float pAttz = 0.032;

vec3 getPL();
vec3 getDrlight();
vec3 getSL();

void main() {
    n = texture(normMap, uv).rgb;
    n = n * 2.0 - 1.0;
    n = normalize(TBN * n);

    vec3 result = getDrlight();
    result += getPL(), getPL();
    FragColor = vec4(result, 1.0);
}


vec3 getDrlight() {
    vec3 objCol = texture(diffMap, uv).rgb;
    float specStrength = texture(specMap, uv).r;

    vec3 ambient = objCol * lightCl * ambientF;

    float diffuseF = dot(n, -lightDr);
    diffuseF = max(diffuseF, 0.0f);
    vec3 diffuse = objCol * lightCl * diffuseF;

    vec3 viewDir = normalize(viewPos - posInWS);
    vec3 H = normalize(-lightDr + viewDir);
    float specLevel = dot(n, H);
    specLevel = max(specLevel, 0.0);
    specLevel = pow(specLevel, shine);
    vec3 specular = lightCl * specLevel * specStrength;

    return ambient + diffuse + specular;
}

vec3 getPL() {

    vec3 objCol = texture(diffMap, uv).rgb;
    float specStrength = texture(specMap, uv).r;

    float distance = length(plightpos - posInWS);
    float attn = 1.0 / (pAttx + (pAtty * distance) + (pAttz * (distance * distance)));

    vec3 lightDir = normalize(plightpos - posInWS);

    vec3 ambient = objCol * lightCl * ambientF;

    vec3 n = normalize(Normal);
    float diffuseF = dot(n, -lightDir);
    diffuseF = max(diffuseF, 0.0f);
    vec3 diffuse = objCol * lightCl * diffuseF;

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


vec3 getSL() {
    vec3 objCol = texture(diffMap, uv).rgb;
    float specStrength = texture(specMap, uv).r;

    float distance = length(slpos - posInWS);
    float attn = 1.0 / (sAtt.x + (sAtt.y * distance) + (sAtt.z * (distance * distance)));

    vec3 lightDir = normalize(slpos - posInWS);

    vec3 ambient = objCol * slcol * ambientF;

    float diffuseF = dot(n, -lightDir);
    diffuseF = max(diffuseF, 0.0f);
    vec3 diffuse = objCol * slcol * diffuseF;

    vec3 viewDir = normalize(viewPos - posInWS);
    vec3 H = normalize(-lightDir + viewDir);
    float specLevel = dot(n, H);
    specLevel = max(specLevel, 0.0);
    specLevel = pow(specLevel, shine);
    vec3 specular = slcol * specLevel * specStrength;

    // Spotlight
    float theta = dot(-lightDir, normalize(sldir));
    float denom = (sRadii.x - sRadii.y);
    float intensity = (theta - sRadii.y) / denom;
    intensity = clamp(intensity, 0.0, 1.0);
    diffuse = diffuse * intensity;
    specular = specular * intensity;

    return diffuse + specular;
}