#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec3 color;
out vec2 texCoord;
out vec3 Normal;
out vec3 currentPos; // used to calculat the dir of light

uniform mat4 camMatrix;
uniform mat4 model;


void main()
{

	currentPos = vec3(model * vec4(aPos, 1.0f));
	
	// Outputs the positions/coordinates of all vertices
	//gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
	//gl_Position = proj * view * model * vec4(aPos, 1.0);
	//camMatrix now does all our transformations
	
	gl_Position = camMatrix * vec4(currentPos, 1.0);
	
	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
	texCoord = aTex;
	Normal = aNormal;
}