//ten plik robi brzydkie okno

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
////verices for box cube
//GLfloat boxVertices[] = {
//	//     COORDINATES   //   COLORS (RGB)   //      NORMALS    
//	-0.1f, -0.1f,  0.1f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,  1.0f, 
//	-0.1f, -0.1f, -0.1f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f, -1.0f,  
//	 0.1f, -0.1f, -0.1f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,  
//	 0.1f, -0.1f,  0.1f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f, 1.0f,   
//	-0.1f,  0.1f,  0.1f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,   
//	-0.1f,  0.1f, -0.1f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f, 
//	 0.1f,  0.1f, -0.1f,  0.5f, 0.5f, 0.5f,  0.0f,  0.0f, -1.0f,  
//	 0.1f,  0.1f,  0.1f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,   
//};
//
////verices for light cube
//GLfloat lightVertices[] = {
//	//     COORDINATES    
//	-0.1f, -0.1f,  0.1f,  
//	-0.1f, -0.1f, -0.1f,  
//	 0.1f, -0.1f, -0.1f, 
//	 0.1f, -0.1f,  0.1f,  
//	-0.1f,  0.1f,  0.1f,  
//	-0.1f,  0.1f, -0.1f,  
//	 0.1f,  0.1f, -0.1f,  
//	 0.1f,  0.1f,  0.1f,  
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
//glm::vec3 cubePositions[] = {
//	glm::vec3(-1.0f, -1.0f, 0.0f),
//	glm::vec3(1.0f,  1.0f, 0.0f), // Bottom-left corner
//	glm::vec3(-1.0f,  1.0f, 0.0f), // Top-left corner
//	glm::vec3(1.0f, -1.0f, 0.0f), // Bottom-right corner
//	
//};
//
//float leftShutterRotation = 0.0f;
//float rightShutterRotation = 0.0f;
//
//void processInput(GLFWwindow* window) {
//	// Check if the escape key is pressed to close the window
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//
//	// Handle the UP arrow key to open the shutters
//	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//		if (leftShutterRotation < 90.0f) {
//			leftShutterRotation += 1.0f; // Open left shutter
//		}
//		if (rightShutterRotation > -90.0f) {
//			rightShutterRotation -= 1.0f; // Open right shutter
//		}
//	}
//
//	// Handle the DOWN arrow key to close the shutters
//	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//		if (leftShutterRotation > 0.0f) {
//			leftShutterRotation -= 1.0f; // Close left shutter
//		}
//		if (rightShutterRotation < 0.0f) {
//			rightShutterRotation += 1.0f; // Close right shutter
//		}
//	}
//}
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
//
//	glfwMakeContextCurrent(window);
//	gladLoadGL();
//	glViewport(0, 0, width, height);	
//
//	//////////////////////////gen cubes for window frame////////////////////////////////////
//	Shader shaderProgram("kolorSwiatlo.vert", "kolorSwiatlo.frag");
//	
//	VAO boxVAO;
//	boxVAO.Bind();
//	VBO boxVBO(boxVertices, sizeof(boxVertices));
//	EBO boxEBO(lightIndices, sizeof(lightIndices));
//	// position
//	boxVAO.LinkAttrib(boxVBO, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
//	// color
//	boxVAO.LinkAttrib(boxVBO, 1, 3, GL_FLOAT, 9 * sizeof(float), (void*)(3*sizeof(float)));
//	//normals - for light
//	boxVAO.LinkAttrib(boxVBO, 2, 3, GL_FLOAT, 9 * sizeof(float), (void*)(6*sizeof(float)));
//	
//	boxVAO.Unbind();
//	boxVBO.Unbind();
//	boxEBO.Unbind();
//
//	///////////////////////////////generating the lightsource/////////////////////////////////////
//	Shader lightShader("light.vert", "light.frag");
//	
//	VAO lightVAO;
//	lightVAO.Bind();
//	VBO lightVBO(lightVertices, sizeof(lightVertices));
//	EBO lightEBO(lightIndices, sizeof(lightIndices));
//	// Links VBO attributes such as coordinates and colors to VAO
//	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
//	
//	lightVAO.Unbind();
//	lightVBO.Unbind();
//	lightEBO.Unbind();
//
//
//	/////////////////////// light stuff using shaders//////////////////////////////
//	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
//	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 2.5f);
//	glm::mat4 lightModel = glm::mat4(1.0f);
//	lightModel = glm::translate(lightModel, lightPos);
//
//	// light cube shader defined outside the main loop - doesnt change
//	lightShader.Activate();
//	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
//	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//
//	shaderProgram.Activate();
//	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//
//	glEnable(GL_DEPTH_TEST);
//	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
//
//
//	// Main while loop
//	while (!glfwWindowShouldClose(window))
//	{
//		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		
//		//allows keyboard inputs
//		processInput(window);
//		camera.Inputs(window);
//		camera.updateMatrix(45.0f, 0.1f, 100.0f);
//
//		//cam activate
//		shaderProgram.Activate();
//		camera.Matrix(shaderProgram, "camMatrix");
//
//		glm::mat4 cubeModel = glm::mat4(1.0f);
//
//
//		glm::mat4 identityMatrix = glm::mat4(1.0f);
//		glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
//		
//		//dolna pozioma
//		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 0.2f, 2.0f));
//		model = scaleMatrix;
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		boxVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//
//		// prawa pionowa
//		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 2.0f, 0.2f));
//		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 0.2f, 0.0f));
//
//		model = translateMatrix * rotateZMatrix * scaleMatrix;
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		boxVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//		// lewa pionowa
//		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 2.0f, 0.2f));
//		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.2f, 0.2f, 0.0f));
//
//		model = translateMatrix * rotateZMatrix * scaleMatrix;
//		
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		boxVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//		//left shutter
//		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 2.0f, 0.22f));
//		
//		//translaate so the window is closed
//		glm::mat4 translateMatrix2 = glm::translate(identityMatrix, glm::vec3(-0.1f, 0.2f, 0.2f));
//
//		//translate so the center of the window is on the frame
//		glm::mat4 translateMatrix1 = glm::translate(identityMatrix, glm::vec3(-0.1f, 0.0f, 0.0f));
//		
//		//rotate agains y axis
//		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(leftShutterRotation), glm::vec3(0.0f, -1.0f, 0.0f));
//
//		//translate back to right pos
//		glm::mat4 translateMatrix3 = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
//
//		model = translateMatrix1 * translateMatrix2 * scaleMatrix * rotateZMatrix * translateMatrix3;
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		boxVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//
//		// Scale the right shutter
//		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 2.0f, 0.2f));
//
//		// Translate to correct position (relative to window)
//		translateMatrix1 = glm::translate(identityMatrix, glm::vec3(0.1f, 0.2f, 0.22f)); 
//
//		// Translate so the center of the shutter aligns with the outer edge of the window
//		translateMatrix2 = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
//
//		// Rotate around the outer edge (Y-axis rotation)
//		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rightShutterRotation), glm::vec3(0.0f, -1.0f, 0.0f));
//
//		// Translate it back to its final position relative to the window frame
//		translateMatrix3 = glm::translate(identityMatrix, glm::vec3(-0.1f, 0.0f, 0.0f));
//
//		model = translateMatrix1 * translateMatrix2 * scaleMatrix * rotateZMatrix * translateMatrix3;
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		boxVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//		
//		// gorna pozioma
//		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 0.2f, 2.0f));
//		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.4f, 0.0f));
//
//		model = translateMatrix  * scaleMatrix;
//		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		boxVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//
//
//
//		// camera stuff 
//		lightShader.Activate();
//		camera.Matrix(lightShader, "camMatrix");
//		
//		//light source box - draw
//		lightVAO.Bind();
//		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//
//	// Delete all the objects we've created
//	//VAO1.Delete();
//	//VBO1.Delete();
//	//EBO1.Delete();
//	//dogTex.Delete();
//	shaderProgram.Delete();
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	return 0;
//
//	
//}