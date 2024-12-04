#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// uniform holding the light coming from our cube
uniform vec4 lightColor;

void main()
{
	FragColor = lightColor;
}