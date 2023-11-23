#version 330 core

out vec4 FragCl;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 cubecl;
uniform vec3 lightDir; // Directional light direction

void main() {
    // Diffuse lighting
    float diff = max(dot(normalize(Normal), -lightDir), 0.0);
    vec3 diffuse = cubecl * diff;

    // Combine ambient and diffuse lighting
    vec3 result = diffuse;

    FragCl = vec4(result, 1.0);
}
