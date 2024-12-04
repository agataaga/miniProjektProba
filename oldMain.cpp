//ten plik robi piramidke

//#include<iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include "include/stb/stb_image.h"
//#include "include/glm/gtc/matrix_transform.hpp"
//#include "include/glm/gtc/type_ptr.hpp"
//
//#include"shaderClass.h"
//#include"VAO.h"
//#include"VBO.h"
//#include"EBO.h"
//#include "camera.h"
//#include "Texture.h"
//
//
//const unsigned int width = 800;
//const unsigned int height = 800;
//
////// Vertices coordinates for a piramid
////GLfloat vertices[] =
////{ //     COORDINATES     /        COLORS      /   TexCoord  //
////	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
////	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
////	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
////	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
////	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
////};
////
////// Indices for vertices order - piramid
////GLuint indices[] =
////{
////	0, 1, 2,
////	0, 2, 3,
////	0, 1, 4,
////	1, 2, 4,
////	2, 3, 4,
////	3, 0, 4
////};
//
//// Vertices coordinates
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
//
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side
//
//	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
//
//	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side
//
//	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
//	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
//	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2, // Bottom side
//	0, 2, 3, // Bottom side
//	4, 6, 5, // Left side
//	7, 9, 8, // Non-facing side
//	10, 12, 11, // Right side
//	13, 15, 14 // Facing side
//};
//
////verices for lifht cube
//GLfloat lightVertices[] =
//{ //     COORDINATES     //
//	-0.1f, -0.1f,  0.1f,
//	-0.1f, -0.1f, -0.1f,
//	 0.1f, -0.1f, -0.1f,
//	 0.1f, -0.1f,  0.1f,
//	-0.1f,  0.1f,  0.1f,
//	-0.1f,  0.1f, -0.1f,
//	 0.1f,  0.1f, -0.1f,
//	 0.1f,  0.1f,  0.1f
//};
//
//GLuint lightIndices[] =
//{
//	0, 1, 2,
//	0, 2, 3,
//	0, 4, 7,
//	0, 7, 3,
//	3, 7, 6,
//	3, 6, 2,
//	2, 6, 5,
//	2, 5, 1,
//	1, 5, 4,
//	1, 4, 0,
//	4, 5, 6,
//	4, 6, 7
//};
//
//
//int main()
//{
//	// Initialize GLFW
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(width, height, "mywindow", NULL, NULL);
//	// Error check if the window fails to create
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	gladLoadGL();
//	glViewport(0, 0, width, height);
//
//
//	// Generates Shader object using shaders defualt.vert and default.frag - used for piramid object
//	Shader shaderProgram("default.vert", "default.frag");
//
//	///////////////////////////////generating the piramid/////////////////////////////////////
//	// Generates Vertex Array Object and binds it
//	VAO VAO1;
//	VAO1.Bind();
//
//	VBO VBO1(vertices, sizeof(vertices));
//	EBO EBO1(indices, sizeof(indices));
//
//	//position
//	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//	//color
//	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//	// textures
//	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//	//normals
//	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//	// Unbind all to prevent accidentally modifying them
//	VAO1.Unbind();
//	VBO1.Unbind();
//	EBO1.Unbind();
//
//	///////////////////////////////generating the lightsource/////////////////////////////////////
//	Shader lightShader("light.vert", "light.frag");
//	VAO lightVAO;
//	lightVAO.Bind();
//	VBO lightVBO(lightVertices, sizeof(lightVertices));
//	EBO lightEBO(lightIndices, sizeof(lightIndices));
//	// Links VBO attributes such as coordinates and colors to VAO
//	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
//	// Unbind all to prevent accidentally modifying them
//	lightVAO.Unbind();
//	lightVBO.Unbind();
//	lightEBO.Unbind();
//
//	/////////////////////// light stuff using shaders//////////////////////////////
//	glm::vec4 lightColor = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
//	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
//	glm::mat4 lightModel = glm::mat4(1.0f);
//	lightModel = glm::translate(lightModel, lightPos);
//
//	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
//	glm::mat4 pyramidModel = glm::mat4(1.0f);
//	pyramidModel = glm::translate(pyramidModel, pyramidPos);
//
//
//	lightShader.Activate();
//	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
//	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	shaderProgram.Activate();
//	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
//	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//
//
//
//
//	// TEXTURES!
//	Texture dogTex("dawid.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
//	dogTex.texUnit(shaderProgram, "tex0", 0);
//
//	glEnable(GL_DEPTH_TEST);
//
//	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
//
//	// Main while loop
//	while (!glfwWindowShouldClose(window))
//	{
//		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//allows keyboard inputs
//		camera.Inputs(window);
//		camera.updateMatrix(45.0f, 0.1f, 100.0f);
//
//		shaderProgram.Activate();
//		camera.Matrix(shaderProgram, "camMatrix");
//
//		dogTex.Bind();
//
//		VAO1.Bind();
//
//		// Draw primitives, number of indices, datatype of indices, index of indices
//		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//		lightShader.Activate();
//		camera.Matrix(lightShader, "camMatrix");
//		//bind the light vao and draw it
//		lightVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//
//	// Delete all the objects we've created
//	VAO1.Delete();
//	VBO1.Delete();
//	EBO1.Delete();
//	dogTex.Delete();
//	shaderProgram.Delete();
//	// Delete window before ending the program
//	glfwDestroyWindow(window);
//	// Terminate GLFW before ending the program
//	glfwTerminate();
//	return 0;
//}