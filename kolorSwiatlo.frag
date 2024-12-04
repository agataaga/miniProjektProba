#version 330 core

out vec4 FragColor;

// Inputs from the vertex shader
in vec3 fragColor;    
in vec3 Normal;       
in vec3 currentPos;   

// Uniforms
uniform vec4 lightColor; 
uniform vec3 lightPos;   

void main()
{
   float ambient = 0.2f;

   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(lightPos - currentPos);

   float diffuse = max(dot(normal, lightDirection), 0.0f);

   FragColor = vec4(fragColor, 1.0f) * lightColor * (diffuse + ambient);
}
